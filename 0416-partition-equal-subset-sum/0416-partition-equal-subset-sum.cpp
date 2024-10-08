class Solution {
public:
    bool rec(vector<int>&arr, int i, int sum1, int sum2){
        if(sum1==sum2) return true;
        if(i==0){
            return sum1==sum2;
        }

        bool notpick = rec(arr, i-1, sum1, sum2);
        bool pick = rec(arr, i-1, sum1-arr[i], sum2+arr[i]);

        return notpick||pick;
    }

    bool rec2(vector<int>&arr, int i, int sum){
        if(sum==0) return true;
        if(i==0) return arr[0]==sum;

        bool notpick = rec2(arr, i-1, sum);
        bool pick = false;
        if(sum>=arr[i])
            pick = rec2(arr, i-1, sum-arr[i]);

        return notpick || pick;
    }
   
    bool memo(vector<int>&arr, int i, int sum1, int sum2, vector<vector<vector<int>>>&dp){
        if(sum1==sum2) return true;
        if(i==0){
            return sum1==sum2;
        }
        if(dp[i][sum1][sum2]!=-1) return dp[i][sum1][sum2];
        bool notpick = memo(arr, i-1, sum1, sum2, dp);
        bool pick = memo(arr, i-1, sum1-arr[i], sum2+arr[i], dp);

        return dp[i][sum1][sum2] = notpick||pick;
    }


    bool memo2(vector<int>&arr, int i, int sum, vector<vector<int>>&dp){
        if(sum==0) return true;
        if(i==0) return arr[0]==sum;

        if(dp[i][sum]!=0) return dp[i][sum];

        bool notpick = memo2(arr, i-1, sum, dp);
        bool pick = false;
        if(sum>=arr[i])
            pick = memo2(arr, i-1, sum-arr[i], dp);

        return dp[i][sum] = notpick || pick;
    }

    int tab(vector<int>&arr, int n, int target){        
        vector<vector<bool>>dp(n, vector<bool>(target+1,false));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if (arr[0] <= target) dp[0][arr[0]] = true;

        for(int i=1; i<n; i++){
            for(int sum = 0; sum<=target; sum++){
                bool notpick = dp[i-1][sum];
                bool pick = false;
                if(sum>=arr[i])
                    pick = dp[i-1][sum-arr[i]];

                dp[i][sum] = notpick || pick;
            }
        }
        return dp[n-1][target];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++) sum += nums[i];
        if(sum%2==1) return false;

        // recursion --- 2nd one better
        // return rec(nums, n-1, sum, 0);
        // return rec2(nums, n-1, sum/2);

        // dp memoization ---        

        // using 3d --
        /*
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(sum+1, vector<int>(sum+1, -1)));
        return memo(nums, n-1, sum, 0, dp);
        */

        // using 2d ---
        /*
        vector<vector<int>>dp(n, vector<int>(sum/2 +1 , -1));
        return memo2(nums, n-1, sum/2, dp);
        */

        // dp tabulation ---
        return tab(nums, n, sum/2);


    }
};