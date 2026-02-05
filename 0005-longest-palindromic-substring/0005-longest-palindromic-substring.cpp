class Solution {
public:
    bool check_pal(string &s){        
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    
    string res = "";
    void expand(string &s, int left, int right){
        while(left>=0 && right<s.size()){
            if(s[left]!=s[right]) break;
            left--;
            right++;
        }
        if(res.size()<right-left) res = s.substr(left+1, right-left-1);
    }

    string longestPalindrome(string s) {
        // tle - o(n^3)
        /*
        int n = s.size();
        string ans = "";
        int size = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n;j++){
                int len = j-i+1;
                string t = s.substr(i, len);
                if(check_pal(t)){
                    if(t.size()>size){
                        size = t.size();
                        ans = t;
                    }
                }
            }
        }
        return ans;
        */
        
        // o(n^3) -- tle
        /*
        int n = s.size();
        vector<string>substring;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=i; j<n; j++){
                temp+=s[j];
                substring.push_back(temp);
            }
        }

        int max_len = 1;
        string ans = substring[0];
        int m = substring.size();
        for(int i=1; i<m; i++){
            int len = substring[i].size();
            if(check_pal(substring[i])){
                if(len > max_len){
                    max_len = len;
                    ans = substring[i];
                }
            }
        }
        return ans;
        */

        for(int i=0; i<s.size(); i++){
            expand(s, i, i);
            expand(s, i, i+1);
        }
        return res;
        
    }
};