class Solution {
public:
    int rec(vector<int>&nums, int start){
        if(start==0) return nums[start];
        if(start<0) return 0;

        int pick = nums[start] + rec(nums, start-2);
        int not_pick = rec(nums, start-1);

        return max(pick, not_pick);
    }

    int memo(vector<int>&nums, int start, vector<int>&dp){
        if(start==0) return nums[start];
        if(start<0) return 0;

        if(dp[start]!=-1) return dp[start];

        int pick = nums[start] + memo(nums, start-2, dp);
        int not_pick = memo(nums, start-1, dp);

        return dp[start] = max(pick, not_pick);
    }

    int tab(vector<int>&nums, int n){
        vector<int>dp(n,0);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i-2>=0) pick+=dp[i-2];        
            int not_pick = dp[i-1];
            dp[i] = max(pick, not_pick);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // recursion
        // return rec(nums, n-1);

        // dp memoization
        // vector<int>dp(n, -1);
        // return memo(nums, n-1, dp);

        // dp tabulation
        return tab(nums, n);

    }
};