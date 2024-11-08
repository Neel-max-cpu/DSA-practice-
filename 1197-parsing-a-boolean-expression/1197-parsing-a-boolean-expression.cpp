class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char>op;
        stack<char>gates;

        for(auto c:s){
            if(c==',') continue;
            else if(c=='(' || c=='t' || c=='f') op.push(c);
            else if(c=='&' || c=='|' || c=='!') gates.push(c);
            else if(c==')'){
                char gate = gates.top();
                gates.pop();

                bool res;
                if(gate=='&' || gate=='!') res = true;
                else res = false;

                while(op.top()!='('){
                    char val = op.top();
                    op.pop();
                    bool boolval = (val=='t');

                    if(gate=='&') res &= boolval;
                    else if(gate=='|') res |= boolval;
                    else if(gate=='!') res = !boolval;
                } 
                op.pop();
                op.push(res? 't':'f');
            }
        }

        return op.top()=='t';
    }
};