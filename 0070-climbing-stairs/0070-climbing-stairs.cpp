class Solution {
public: 
    int memo(vector<int>&dp, int n){
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = memo(dp, n-1)+memo(dp, n-2);
    }

    int tab(int n){
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1] = 1;        
        for(int i=2; i<=n; i++){
            if(i==2) dp[i] = 2;
            else dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return memo(dp, n);
        return tab(n);
    }
};