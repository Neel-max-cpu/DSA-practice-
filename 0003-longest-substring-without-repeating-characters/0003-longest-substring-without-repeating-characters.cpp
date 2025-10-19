class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0, end = 0;
        unordered_map<char,int>m;
        int len = 0;
        while(end<n){
            char x = s[end];
            if(m.find(x)!=m.end()){
                //if found
                len = max(len, end-start);
                start = end;
                m[x] = end;
                end++;
            }
            else{
                //not found
                m[x] = end;
                end++;
            }
        }
        return max(end-start, len);
    }
};