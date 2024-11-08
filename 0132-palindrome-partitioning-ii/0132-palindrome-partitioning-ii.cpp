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

    int minCut(string s) {
        int n = s.size();       
        // recursion -- 
        // return rec(0, n, s)-1;        

        // dp memoization ---
        vector<int>dp(n, -1);
        return memo(0, n, s, dp)-1;        

    }
};