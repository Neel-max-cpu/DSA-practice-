class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int rec(int i, int n, string s){
        if(i==n) return 0;
        int mincost = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1+rec(j+1, n, s);
                mincost = min(cost, mincost);
            }
        }
        return mincost;
    }
    
    int memo(int i, int &n, string &s, vector<int>&dp){
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];

        int mincost = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(i, j, s)){
                int cost = 1+memo(j+1, n, s, dp);
                mincost = min(cost, mincost);
            }
        }
        return dp[i] = mincost;
    }

    int tab(int &n, string &s){
        // n+1 since we are checking j+1
        vector<int>dp(n+1, 0);
        // base case i==n 0
        dp[n] = 0;
        
        for(int i=n-1; i>=0; i--){
            int mincost = INT_MAX;
            for(int j=i; j<n; j++){
                if(isPalindrome(i, j, s)){
                    int cost = 1+dp[j+1];
                    mincost = min(cost, mincost);
                }
            }
            dp[i] = mincost;
        }
        return dp[0]-1;
    }

    int minCut(string s) {
        int n = s.size();       
        // recursion -- 
        // return rec(0, n, s)-1;        

        // dp memoization ---
        /*
        vector<int>dp(n, -1);
        return memo(0, n, s, dp)-1;        
        */

        // dp tabulation ---
        return tab(n, s);

    }
};