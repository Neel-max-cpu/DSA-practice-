class Solution {
public:
    int rec(int row, int col, vector<vector<int>>&arr){
        if(row==arr.size()-1) return arr[row][col];

        int up = arr[row][col] + rec(row+1, col, arr);
        int down = arr[row][col] + rec(row+1, col+1, arr);

        return min(up, down);
    }
    
    int memo(int row, int col, vector<vector<int>>&arr, vector<vector<int>>&dp){
        if(row==arr.size()-1) return arr[row][col];

        if(dp[row][col]!=-1) return dp[row][col];
        int up = arr[row][col] + memo(row+1, col, arr, dp);
        int down = arr[row][col] + memo(row+1, col+1, arr, dp);

        return dp[row][col] = min(up, down);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // recursion ---
        // return rec(0,0, triangle);

        // dp memoization--
        vector<vector<int>>dp(m, vector<int>(m, -1));
        return memo(0,0, triangle, dp);
    }
};