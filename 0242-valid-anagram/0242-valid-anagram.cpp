class Solution {
public:
    bool isAnagram(string s, string t) { 
        if(s.size()!=t.size()) return false;
        
        unordered_map<char,int>n;
        unordered_map<char,int>m;
        for(auto it:s){
            n[it]++;
        }
        for(auto it:t){
            m[it]++;
        }
        if(m!=n) return false;
        return true;        
    }
};