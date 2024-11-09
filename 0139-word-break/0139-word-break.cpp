class Solution {
public:
    bool rec(int i, int n, string &s, unordered_map<string,int>&m){
        if(i>=n) return false;
        
        int len = n-i;
        string t = s.substr(i, len);
        if(m.find(t)!=m.end()) return true;        
        
        for(int ind=i; ind<n; ind++){
            string t = s.substr(i, ind-i+1);
            if(m.find(t)!=m.end()){
                if(rec(ind+1, n, s, m)) return true;                
            }
        }
        return false;
    }
    
    bool memo(int i, int n, string &s, unordered_map<string,int>&m, unordered_map<int,bool>&dp){
        if(i>=n) return false;
        
        // if(dp.count(i)) return dp[i];
        if(dp.find(i)!=dp.end()) return dp[i];

        int len = n-i;
        string t = s.substr(i, len);
        if(m.find(t)!=m.end()) return true;        
        
        // else if not true iterate
        for(int ind=i; ind<n; ind++){
            string t = s.substr(i, ind-i+1);
            if(m.find(t)!=m.end()){
                if(memo(ind+1, n, s, m, dp)) {
                    return dp[i] = true;                
                }
            }
        }
        return dp[i] = false;
    }
   
    bool memo2(int i, int n, string &s, unordered_map<string,int>&m, unordered_map<int,bool>&dp){
        if(i<0) return true;
        
        // if(dp.count(i)) return dp[i];
        if(dp.find(i)!=dp.end()) return dp[i];

        for (int j = i; j >= 0; --j) {
            string t = s.substr(j, i - j + 1);             
            if (m.find(t) != m.end() && memo2(j - 1, n, s, m, dp)) {
                return dp[i] = true;
            }
        }
        return dp[i] = false;

    }

    bool tab(int n, string &s, unordered_map<string,int>&m){
        vector<bool>dp(n+1, false);
        // base case if(i<0) return true; since empty substring can be segmented
        dp[0] = true;

        for(int i=1; i<=n; i++){
            // check each substring
            // since n+1, so till <i and not <=i
            for(int j=0; j<i; j++){
                string t = s.substr(j, i-j);
                // and here too j and not j-1
                if(dp[j] && m.find(t)!=m.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

    bool wordBreak(string s, vector<string>& v) {
        unordered_map<string,int>m;
        for(auto it:v){
            m[it] = 1;
        }
        int n = s.size();
        // recursion --- can be done from n-1 to 0
        // return rec(0, n, s, m);        

        
        // dp memoization --- can be done from n-1 to 0
        /*
        unordered_map<int,bool>dp;  
        return memo(0, n, s, m, dp);
        */

        

        // unordered_map<int,bool>dp;  
        // return memo2(n-1, n, s, m, dp);
        // dp tabulation --
        return tab(n, s, m);
    }
};