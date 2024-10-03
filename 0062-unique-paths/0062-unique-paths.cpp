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
        
        // dp memoization 
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return memo(m, n, 0, 0, dp);
    }
};