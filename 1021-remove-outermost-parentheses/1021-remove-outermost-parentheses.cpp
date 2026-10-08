class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans="";
        // my solution --
        /*
        int level = 1;
        int open = 0;
        int firstIdx = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                if(level == 1){
                    firstIdx = i;
                }
                level++;
                open++;
            }
            else if(s[i]==')'){
                open--;
                if(open==0 && level>1){
                    // get the sub str after firstIdx
                    int len = (i-1)-(firstIdx+1)+1;                                        
                    ans = ans+s.substr(firstIdx+1, len);
                    level = 1;
                }
            }
        }
        return ans;
        */

        // optimal ---
        int balance = 0;
        for(auto it:s){
            if(it=='('){
                balance++;
                // dont add the first/outermost one
                if(balance>1) ans+=it;
            }
            else{
                balance--;
                // dont add the first/outermost one
                if(balance>0) ans+=it;
            }
        }
        return ans;
    }
};