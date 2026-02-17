class Solution {
public:
    int strStr(string h, string s) {
        int n = h.size();
        int m = s.size();
        for(int i=0; i<n; i++){
            // from index i to length m
            if(n-i<m) return -1;
            else{
                string t = h.substr(i,m);
                if(t==s) return i;
            }            
        }
        return -1;
    }
};