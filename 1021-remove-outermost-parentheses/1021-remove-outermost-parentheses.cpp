class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int level = 1;
        int open = 0;
        int firstIdx = 0;
        string ans="";
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
    }
};