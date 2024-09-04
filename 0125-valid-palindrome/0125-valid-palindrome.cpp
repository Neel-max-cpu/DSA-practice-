class Solution {
public:
    bool isPalindrome(string s) {
        // METHOD 2 -- using alpha numeric - O(n)
        int i = 0, j= s.size()-1;
        while(i<j){
            // isalnum - Alphanumeric characters include letters and numbers, will return true, else return false
            while(!isalnum(s[i]) && i<j) i++;
            while(!isalnum(s[j]) && i<j) j--;

            if(tolower(s[i])!=tolower(s[j])) return false;
            i++;
            j--;
        }       
        return true; 

        // METHOD 1 -- o(n + n)
        /*
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
        */
    }
};