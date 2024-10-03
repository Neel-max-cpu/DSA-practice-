class Solution {
public:
    long long rec(int m, int n, int row, int col, vector<vector<int>>&arr){
        if(row==0 && col==0) return arr[row][col];

        if(row<0 || col<0) return INT_MAX;
        long long  up = arr[row][col] + rec(m, n, row-1, col, arr);
        long long left = arr[row][col] + rec(m, n, row, col-1, arr);    
        return min(up,left);
    }
  
    long long memo(int m, int n, int row, int col, vector<vector<int>>&arr, vector<vector<int>>&dp){
        if(row==0 && col==0) return arr[row][col];

        if(row<0 || col<0) return INT_MAX;
        
        if(dp[row][col]!=-1) return dp[row][col];
        long long  up = arr[row][col] + memo(m, n, row-1, col, arr, dp);
        long long left = arr[row][col] + memo(m, n, row, col-1, arr, dp);    
        return dp[row][col] = min(up,left);
    }

    int tab(int m, int n, vector<vector<int>>&arr){
        vector<vector<int>>dp(m, vector<int>(n,0));

        dp[0][0] = arr[0][0];
        for(int i=1; i<m; i++){        
            dp[i][0] = arr[i][0]+dp[i-1][0];
        }

        for(int i=1; i<n; i++){
            dp[0][i] = arr[0][i] + dp[0][i-1];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int ans = arr[i][j];
                ans += min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = ans;
            }
        }
        return dp[m-1][n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // recrusion ---
        // return rec(m, n, m-1, n-1, grid);

        // dp memoization ---
        /*
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return memo(m, n, m-1, n-1, grid, dp);
        */

        // dp tabulation --
        return tab(m, n, grid);
        
    }
};