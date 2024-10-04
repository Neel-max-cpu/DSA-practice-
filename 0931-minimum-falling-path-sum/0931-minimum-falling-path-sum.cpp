class Solution {
public:
    int rec(int row, int col, vector<vector<int>>&arr){
        if(col<0 || col>=arr.size()) return 1e9;
        
        if(row==arr.size()-1) return arr[row][col];

        int left = arr[row][col] + rec(row+1, col-1, arr);
        int down = arr[row][col] + rec(row+1, col, arr);
        int right = arr[row][col] + rec(row+1, col+1, arr);        

        return min({left, right, down});
    }
    
    int memo(int row, int col, vector<vector<int>>&arr, vector<vector<int>>&dp){
        if(col<0 || col>=arr.size()) return 1e9;
        
        if(row==arr.size()-1) return arr[row][col];

        if(dp[row][col]!=1e9) return dp[row][col];

        int left = arr[row][col] + memo(row+1, col-1, arr, dp);
        int down = arr[row][col] + memo(row+1, col, arr, dp);
        int right = arr[row][col] + memo(row+1, col+1, arr, dp);        

        return dp[row][col]=min({left, right, down});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // recursion ---
        int n = matrix.size();
        int ans = INT_MAX;
        /*
        for(int i=0;i<n; i++){
            ans = min(ans, rec(0, i, matrix));
        }
        return ans;
        */

        // dp memoization ---
        vector<vector<int>>dp(n, vector<int>(n, 1e9));
        for(int i=0;i<n; i++){
            ans = min(ans, memo(0, i, matrix, dp));
        }
        return ans;
    }
};