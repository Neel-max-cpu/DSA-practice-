class Solution {
public:
    int rec(int i, int k, int n, vector<int>&arr){
        if(i>=n) return 0;

        int ans = INT_MIN;
        int maxele = arr[i];
        for(int ind=i; ind<i+k && ind<n; ind++){
            maxele = max(maxele, arr[ind]);
            int partition = (ind-i+1)*maxele + rec(ind+1, k, n, arr);
            ans = max(ans, partition);
        }
        return ans;
    }
    
    int memo(int i, int k, int n, vector<int>&arr, vector<int>&dp){
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int ans = INT_MIN;
        int maxele = arr[i];
        for(int ind=i; ind<i+k && ind<n; ind++){
            maxele = max(maxele, arr[ind]);
            int partition = (ind-i+1)*maxele + memo(ind+1, k, n, arr, dp);
            ans = max(ans, partition);
        }
        return dp[i] = ans;
    }

    int tab(vector<int>&arr, int k, int n){
        vector<int>dp(n+1, 0);
        // base case
        dp[n] = 0;
        
        for(int i=n-1; i>=0; i--){
            int ans = INT_MIN;
            int maxele = arr[i];
            for(int ind=i; ind<i+k && ind<n; ind++){
                maxele = max(maxele, arr[ind]);
                int partition = (ind-i+1)*maxele + dp[ind+1];
                ans = max(ans, partition);
            }
            dp[i] = ans;
        }
        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        // recursion ---
        // return rec(0, k, n, arr);

        // dp memoization ---
        /*
        vector<int>dp(n, -1);
        return memo(0, k, n, arr, dp);
        */

        // dp tabulation --
        return tab(arr, k, n);

    }
};