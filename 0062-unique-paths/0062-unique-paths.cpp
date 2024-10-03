class Solution {
public:
    int rec(int m, int n, int row, int col){
        if(row==m-1 && col==n-1) return 1;

        int right = 0, down = 0;
        if(col+1<n) right += rec(m, n, row, col+1);
        if(row+1<m) down += rec(m, n, row+1, col);
        return right+down; 
    }
    
    int memo(int m, int n, int row, int col, vector<vector<int>>&dp){
        if(row==m-1 && col==n-1) return 1;

        if(dp[row][col]!=-1) return dp[row][col];

        int right = 0, down = 0;
        if(col+1<n) right += memo(m, n, row, col+1, dp);
        if(row+1<m) down += memo(m, n, row+1, col, dp);
        return dp[row][col] = right+down; 
    }

    int uniquePaths(int m, int n) {
        // recursion --
        // return rec(m, n , 0, 0);
        
        // dp memoization ---
        /*
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return memo(m, n, 0, 0, dp);
        */

        // dp tabulation ---
        vector<vector<int>>dp(m, vector<int>(n,0));
        // base case
        for(int i=0; i<n; i++){
            dp[0][i] = 1;
        }
        for(int i=1; i<m; i++){
            dp[i][0] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
};