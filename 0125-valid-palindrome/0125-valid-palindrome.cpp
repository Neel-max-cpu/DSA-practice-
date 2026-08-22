class Solution {
public:
    bool checkPalindrome(string &res){
        cout<<res<<endl;
        int n = res.size();
        for(int i=0; i<n/2; i++){
            if(res[i]!=res[n-1-i]) return false;
        }
        return true;
    }

    bool isPalindrome(string s) {
        string res;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z')){
                res+=tolower(c);
            }
            if(c>='0' && c<='9') res+=c;
        }

        if(checkPalindrome(res)) return true;
        return false;
    }
};