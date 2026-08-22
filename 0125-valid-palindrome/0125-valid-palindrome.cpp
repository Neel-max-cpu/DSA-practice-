class Solution {
public:
    bool checkPalindrome(string &res){
        cout<<res<<endl;
        int n = res.size();
        for(int i=0; i<n/2; i++){
            if(res[i]!=res[n-1-i]) return false;
        }
        return true;

        /*
        int i = 0, j=res.size()-1;        
        while(i<j){
            if(res[i]!=res[j]) return false;
            i++; j--;
        }
        return true;
        */

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

        // or --
        /*
        for(auto it:s){
            if(isalnum(it)){
                res+=tolower(it);
            }
        }
        */

        if(checkPalindrome(res)) return true;
        return false;
    }
};