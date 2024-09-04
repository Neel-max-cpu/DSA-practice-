class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(auto it:s){
            if(it>='a' && it<='z'){
                t+=it;
            }
            else if(it>='A' && it<='Z'){
                t+=tolower(it);
            }
            else if(it>='0' && it<='9'){
                t+=it;
            }
        }

        int i = 0, j=t.size()-1;
        while(i<j){
            if(t[i++]!=t[j--]) return false;
        }
        return true;
    }
};