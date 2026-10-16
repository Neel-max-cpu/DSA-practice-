class Solution {
public:
    bool isValid(int col, int row, int n, vector<string>&temp){
        if(temp.empty()) return true;
        // check directly below of col,row
        for(int i=row-1; i>=0; i--){
            if(temp[i][col]=='Q') return false;
        }

        // check diagonally left below
        int j =col-1;
        for(int i=row-1; i>=0; i--){            
            if(j<0) break;
            if(temp[i][j]=='Q') return false;
            j--;            
        }

        j = col+1;
        // check diagonally right below
        for(int i=row-1; i>=0; i--){            
            if(j>=n) break;
            if(temp[i][j]=='Q') return false;
            j++;            
        }

        return true;
    }

    string getString(int idx, int n){
        string s;
        for(int i = 0; i<n; i++){
            if(i==idx) s+='Q';
            else s+='.';
        }
        return s;
    }
    void helper(int n, int row, vector<string>&temp, vector<vector<string>>&ans){
        if(row>=n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0; i<n; i++){
            string s = getString(i, n);
            if(isValid(i, row, n, temp)){
                temp.push_back(s);
                helper(n, row+1, temp, ans);
                temp.pop_back();
            }
        }
    }

    void helper2(int n, int row, vector<string>& temp,vector<vector<string>>& ans){
        if (row == n) {
            ans.push_back(temp);
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (colUsed[col] || diag1[d1] || diag2[d2])
                continue;

            // Place queen
            temp[row][col] = 'Q';
            // mark as true --
            colUsed[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            helper2(n, row + 1, temp, ans);

            // Backtrack
            temp[row][col] = '.';
            colUsed[col] = diag1[d1] = diag2[d2] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // mine --
        /*
        vector<vector<string>>ans;
        vector<string>temp;
        helper(n, 0, temp, ans);
        return ans;
        */

        // optimal --
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));

        // for straight up
        colUsed.resize(n, false);
        /* 
        A board of size n has 2n-1 diagonals in each direction. eg n=4 then 2(4)-1=7 diagonals, and initiallize it with false

        why 2*n-1 from top left to bottom left(1 in each row = n) & top right to bottom right (1 in each row = n) -- just the 1 in the middle over laps so -1      
        so n+n-1 or 2n-1  
        */

        /*
        for diagonal we are just checking the most furthest element for eg at 4x4
        (right diagonal)
        place queen at 0,0
        then another queen can't be place at 1,1; 2,2; and 3,3
        but do we need to check all - no, we could just mark the further's most as true and check it at o(1)
        similarly for (left diagonal) if we place it at 0,3
        then another queent can't be placed at 1,2; 2,1; and 3,0
        so we can mark at 3,0 
        
        so for right diagonal further most -- row-col+n-1 = 0-0+4-1=3
        so for left diagonal further most -- row+col
        so if we place Q at 0,0 then row+col = 0,0   

        basically mark the furthers eg if we place Q at 0,1 then we can't place at(right)
        1,2 and 2,3
        so right = 0-1+4-1= 2, and we can see putting at 1,2 gives the same 1-2+4-1 = 2
        and left = 0+1 = 1, and we can see putting at 1,0 gives the same 1+0=1

        **basically the entire the gist is the digaonaly value remains constant along their respective diagonals
        **our code doesn't actually mark that board cell. Instead, it marks a Boolean array entry representing the entire diagonal.
        */
        
        diag1.resize(2 * n - 1, false);
        diag2.resize(2 * n - 1, false);

        helper2(n, 0, temp, ans);
        return ans;
    }
    // global --
    vector<bool> colUsed, diag1, diag2;
};