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

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp;
        helper(n, 0, temp, ans);
        return ans;
    }
};