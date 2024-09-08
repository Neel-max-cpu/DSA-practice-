class Solution {
public:
    string minWindow(string s, string t) {
        // o(n+m)
        map<char,int>m1;
        map<char,int>m2;
        
        for(auto it:t){
            m2[it]++;
        }

        int l = 0,r=0;
        int need = m2.size();
        int have = 0;
        int start = 0;
        int len = INT_MAX;        
        
        while(r<s.size()){
            char c = s[r];
            m1[c]++;
        
            // find in t's map
            if(m2.find(c)!=m2.end()){
                if(m1[c]==m2[c]) have++;
            }
        
            while (have == need) {            
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }                
                char x = s[l];
                m1[x]--;                                
                if (m2.find(x) != m2.end() && m1[x] < m2[x]) {
                    have--;
                }                
                l++;
            }            
            r++; 
        }
        if(len==INT_MAX) return "";
        else return s.substr(start, len);
    }
};