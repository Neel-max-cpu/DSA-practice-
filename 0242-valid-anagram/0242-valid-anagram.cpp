class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        vector<int>v(26,0);
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            v[c-'a']++;
        }
        for(int i=0; i<t.size(); i++){
            char c = t[i];
            v[c-'a']--;
        }
        
        for(auto it:v){
            if(it<0 || it>0) return false;
        }
        return true;
    }
};