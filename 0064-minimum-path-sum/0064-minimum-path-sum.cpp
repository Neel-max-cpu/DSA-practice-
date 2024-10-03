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

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // recrusion ---
        // return rec(m, n, m-1, n-1, grid);

        // dp memoization 
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return memo(m, n, m-1, n-1, grid, dp);
        
    }
};