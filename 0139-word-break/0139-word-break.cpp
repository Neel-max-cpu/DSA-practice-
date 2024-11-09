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

    bool wordBreak(string s, vector<string>& v) {
        unordered_map<string,int>m;
        for(auto it:v){
            m[it] = 1;
        }
        int n = s.size();
        // recursion ---
        // return rec(0, n, s, m);        

        // dp memoization ---
        unordered_map<int,bool>dp;  
        return memo(0, n, s, m, dp);
    }
};