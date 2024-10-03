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

    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        // recursion --
        // return rec(n, m, n-1, m-1, arr);

        // dp memoization --
        vector<vector<int>>dp(n, vector<int>(m,-1));        
        return memo(n, m, n-1, m-1, arr, dp);
        

    }
};