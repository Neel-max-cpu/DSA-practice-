class Solution {
public:
    int rec(vector<int>&nums, int n){
        if(n==0) {
            return nums[0];            
        }
        if(n<0) return 0;

        int pick = nums[n] + rec(nums, n-2);
        int not_pick = rec(nums, n-1);

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
        if(n==1) return nums[0];
        // from 1 to n-1
        vector<int>temp1;
        // from 0 to n-2;
        vector<int>temp2;
        for(int i=0; i<n; i++){
            if(i==0) temp2.push_back(nums[i]);
            else if(i==n-1) temp1.push_back(nums[i]);
            else {
                temp1.push_back(nums[i]);
                temp2.push_back(nums[i]);
            }
        }
        int N = temp1.size();

        // recursion
        // return max(rec(temp1, N-1), rec(temp2, N-1));

        // dp memoization
        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        return max(memo(temp1, N-1, dp1), memo(temp2, N-1, dp2));

        // dp tabulation
        // return tab(nums, n);

        // space optimization --         
        // int prev = nums[0], prev2 = 0;
        // for(int i=1; i<n; i++){
        //     int pick = nums[i];
        //     if(i-2>=0) pick+=prev2;        
        //     int not_pick = prev;
            
        //     prev2 = prev;
        //     prev = max(pick, not_pick);
        // }
        // return prev;

    }
};