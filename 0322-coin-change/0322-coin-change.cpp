class Solution {
public:

    int helper(vector<int>&arr, int k){
        if(k==0) return 0;
        if(k<0) return INT_MAX;

        int minCoins = INT_MAX;
        for(auto it:arr){
            int ans = helper(arr, k-it);
            if(ans != INT_MAX){
                minCoins = min(ans+1, minCoins);
            }
        }
        return minCoins;

    }

    int helper2(vector<int>&arr, int k, vector<int>&dp){
        if(k==0) return 0; 
        if(k<0) return INT_MAX;
        if(dp[k] != -1) return dp[k];

        int minCoins = INT_MAX;
        for(auto it: arr){
            int ans = helper2(arr, k-it, dp);
            if(ans!=INT_MAX){
                minCoins = min(minCoins,ans+1);
            }
        }
        dp[k] = minCoins;
        return minCoins;
    }


    int coinChange(vector<int>& coins, int amount) {
        // greedy won't give correct for all answer ---
        /*
        sort(coins.begin(), coins.end());
        int i = coins.size()-1;
        int ans = 0;
        while(i>=0){
            if(coins[i]<=amount){
                amount -= coins[i];
                ans++;
            }
            else{
                i--;
            }
        }
        if(amount==0) return ans;
        else return -1;
        */

        // recursion ---  tle
        /*
        int ans = helper(coins, amount);
        return ans == INT_MAX? -1:ans;
        */

        // dp memo --
        /*
        vector<int>dp(amount+1, -1);
        int ans = helper2(coins, amount, dp);
        return ans == INT_MAX? -1: ans;
        */

        // dp tabulation --
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(auto it:coins){
                if(i-it>=0 && dp[i-it]!= INT_MAX){
                    // similar to rec/memo = min(int_max, res+1)
                    dp[i] = min(dp[i], dp[i-it]+1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1:dp[amount];
    }
};