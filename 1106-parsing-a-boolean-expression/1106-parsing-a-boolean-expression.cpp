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
                /*
                For an AND operation, all values within the parentheses need to be true 
                for the entire expression to be true.Therefore, we start with result = true. 
                This way, any false within the expression will change result to false as soon as 
                it is encountered

                For an OR operation, the expression is true if at least one value 
                inside the parentheses is true.Starting with result = false allows us to change 
                result to true upon encountering the first true value.

                Although result is initially set to true, this is just a placeholder. The actual 
                result will be the opposite of the first operand within the parentheses, as processed 
                in result = !boolVal.

                */
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