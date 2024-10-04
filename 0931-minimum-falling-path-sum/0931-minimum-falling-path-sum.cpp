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

    int tab(vector<vector<int>>&arr, int n){
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i=0; i<n; i++){
            dp[n-1][i] = arr[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                dp[i][j] = arr[i][j];
                int left = 1e9, right = 1e9;
                if(j>0) left = dp[i+1][j-1];
                if(j<n-1) right = dp[i+1][j+1];
                int down = dp[i+1][j];
                dp[i][j] += min({left, right, down});
            }
        }

        int ans = dp[0][0];
        for(int i=1; i<n; i++){
            ans = min(ans, dp[0][i]);
        }

        return ans;
    }
    
    int so(vector<vector<int>>&arr, int n){
        vector<int>prev(n,0);

        for(int i=0; i<n; i++){
            prev[i] = arr[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            vector<int>temp(n,0);
            for(int j=0; j<n; j++){
                temp[j] = arr[i][j];
                int left = 1e9, right = 1e9;
                if(j>0) left = prev[j-1];
                if(j<n-1) right = prev[j+1];
                int down = prev[j];
                temp[j] += min({left, right, down});
            }
            prev = temp;
        }

        int ans = prev[0];
        for(int i=1; i<n; i++){
            ans = min(ans, prev[i]);
        }

        return ans;
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
        /*
        vector<vector<int>>dp(n, vector<int>(n, 1e9));
        for(int i=0;i<n; i++){
            ans = min(ans, memo(0, i, matrix, dp));
        }
        return ans;
        */

        // dp tabulation ---
        // return tab(matrix, n);

        // space optimization --
        return so(matrix, n);
    }
};