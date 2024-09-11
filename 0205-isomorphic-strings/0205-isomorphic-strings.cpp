class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>m1;
        map<char,char>m2;
        int n = s.size();
        if(n!=t.size()) return false;
        for(int i=0; i<n;i++){
            char c1 = s[i];
            char c2 = t[i];
            // if not found map it
            if(m1.find(c1)==m1.end()) m1[c1]=t[i];
            if(m2.find(c2)==m2.end()) m2[c2]=s[i];            
            char x = m1[c1];
            char y = m2[c2];
            if(x!=t[i] || y!=s[i]) return false;         
        }
        return true;
    }
};