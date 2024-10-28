class Solution {
public:
    void subs(string s, int i, set<string>&st, string t){
        if(i==s.size()){
            st.insert(t);
            return;
        }

        t+=s[i];
        subs(s, i+1, st, t);
        t.pop_back();
        subs(s, i+1, st, t);
    }

    int rec(string s1, string s2, int i, int j){
        if(i<0 || j<0){
            return 0;
        }

        int pick = 0;
        if(s1[i]==s2[j]) pick = 1+rec(s1, s2, i-1, j-1);

        // if doesn't match
        int notpick1 = 0, notpick2=0;
        notpick1 = 0 + rec(s1,s2,i-1,j);
        notpick2 = 0 + rec(s1,s2,i,j-1);

        return max({pick, notpick1, notpick2});
    }
    
    int memo(string s1, string s2, int i, int j, vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int pick = 0;
        if(s1[i]==s2[j]) pick = 1+memo(s1, s2, i-1, j-1, dp);

        // if doesn't match
        int notpick1 = 0, notpick2=0;
        notpick1 = 0 + memo(s1,s2,i-1,j, dp);
        notpick2 = 0 + memo(s1,s2,i,j-1, dp);

        return dp[i][j] = max({pick, notpick1, notpick2});
    }

    int tab(string &s1, string &s2, int n, int m){
        vector<vector<int>>dp(n, vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // base case if i<0 && j<0 then 0 so, initiallized pick,np1, np2 to 0
                int pick = 0;
                if(s1[i]==s2[j]){
                    pick = 1;
                    if(i!=0 && j!=0) pick+=dp[i-1][j-1];
                }
                int notpick1 = 0, notpick2=0;
                if(i!=0) notpick1+=dp[i-1][j];
                if(j!=0) notpick2+=dp[i][j-1];

                dp[i][j] = max({pick, notpick1, notpick2});
            }
        }
        return dp[n-1][m-1];
    }
    
    int so(string &s1, string &s2, int n, int m){        
        vector<int>prev(m, 0);

        for(int i=0; i<n; i++){
            vector<int>curr(m,0);
            for(int j=0; j<m; j++){
                // base case if i<0 && j<0 then 0 so, initiallized pick,np1, np2 to 0
                int pick = 0;
                if(s1[i]==s2[j]){
                    pick = 1;
                    if(i!=0 && j!=0) pick+=prev[j-1];
                }
                int notpick1 = 0, notpick2=0;
                if(i!=0) notpick1+=prev[j];
                if(j!=0) notpick2+=curr[j-1];

                curr[j] = max({pick, notpick1, notpick2});
            }
            prev = curr;
        }
        return prev[m-1];
    }


    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
       
        // brute force ----
        /*
        set<string>st1;
        set<string>st2;
        subs(s1, 0, st1, "");
        subs(s2, 0, st2, "");

        int count = 0;
        for(auto it:st1){
            if(st2.find(it)!=st2.end()){
                int a = it.size();
                count = max(count, a);
            }
        }
        return count;
        */   

        // recursion ---
        // return rec(s1, s2, n-1, m-1);

        // dp memoization ---
        /*
        vector<vector<int>>dp(n, vector<int>(m,-1));    
        return memo(s1, s2, n-1, m-1, dp);
        */

        // dp tabulation ---
        // return tab(s1, s2, n, m);

        // space optimization --
        return so(s1, s2, n, m);

    }
};