class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;    
        int ans = 0;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                s.push(stoi(tokens[i]));
            }
            else{
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(tokens[i]=="+") ans = a+b;
                else if(tokens[i]=="-") ans = a-b;
                else if(tokens[i]=="*") ans = a*b;
                else if(tokens[i]=="/") ans = a/b;
                s.push(ans);
            }
        }
        return s.top();
    }
};