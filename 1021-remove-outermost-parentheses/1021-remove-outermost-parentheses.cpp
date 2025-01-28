class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char>t;
        int f = 0;
        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i]=='(' && f==0){
                f = 1;
            }
            else if(s[i]=='(' && f==1){
                ans+=s[i];
                t.push(s[i]);
            }
            else if(s[i]==')'){                
                if(!t.empty() && t.top()=='('){
                    t.pop();
                    ans+=s[i];
                }
                else{
                    // stack is empty
                    f = 0;
                }
            }
        }
        return ans;
    }
};