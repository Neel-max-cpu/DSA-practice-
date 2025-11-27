class Solution {
public:
    bool check(int row, int col, vector<string>&current, int n){
        // from top to col
        for(int i=row-1; i>=0; i--){
            if(current[i][col]=='Q') return false;
        }

        // diagonal from upper left to right
        int i = row-1, j=col-1;
        while(i>=0 && j>=0){
            if(current[i][j]=='Q') return false;
            i--;
            j--;
        }

        // diagonal from upper right to left(from lower left to right)
        i = row-1;
        j=col+1;
        while(i>=0 && j<n){
            if(current[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }

    void putQueens(vector<vector<string>>&ans, vector<string>&current, int n, int row){
        if(row==n){
            ans.push_back(current);
            return;
        }
        for(int j=0; j<n; j++){
            //if putting queen in ith col valid
            if(check(row, j, current, n)){                
                current[row][j] = 'Q';                
                putQueens(ans, current, n, row+1);
                current[row][j] = '.';                                
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>current;
        string s(n, '.');
        for(int i=0; i<n; i++){
            current.push_back(s);
        }
        // basically is n = 3, then ["...", "...", "..."] in current
        putQueens(ans, current, n, 0);
        return ans;
    }
};