class Solution {
public:
    int rec(int n, int m, int row, int col, vector<vector<int>>&arr){
        if(row==0 && col==0) return 1;
        
        if(row<0 || col<0 || arr[row][col]==1) return 0;
        int up = rec(n,m,row-1, col, arr);
        int down = rec(n,m, row, col-1, arr);
        return up+down;
    }
    
    int memo(int n, int m, int row, int col, vector<vector<int>>&arr, vector<vector<int>>&dp){
        if(row==0 && col==0){
            if(arr[row][col]==0) return 1;
            else return 0;
        }         
        
        if(row<0 || col<0 || arr[row][col]==1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = memo(n,m,row-1, col, arr, dp);
        int down = memo(n,m, row, col-1, arr, dp);
        return dp[row][col] = up+down;
    }

    int tab(int n, int m, vector<vector<int>>&arr){
        vector<vector<int>>dp(n, vector<int>(m, 0));
        
        int i = 0;
        while(i<n){
            if(arr[i][0]==0) {
                dp[i][0] = 1;
                i++;
            }
            else break;
        }

        i = 0;
        while(i<m){
            if(arr[0][i]==0) {
                dp[0][i] = 1;
                i++;
            }
            else break;

        }
    
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(arr[i][j]==1) dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        // recursion --
        // return rec(n, m, n-1, m-1, arr);

        // dp memoization --
        /*
        vector<vector<int>>dp(n, vector<int>(m,-1));        
        return memo(n, m, n-1, m-1, arr, dp);
        */

        // dp tabulation ---
        return tab(n, m, arr);
        

    }
};