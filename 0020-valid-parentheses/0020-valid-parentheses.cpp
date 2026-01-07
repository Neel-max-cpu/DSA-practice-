class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='[') st.push(it);
            else {
                if(st.empty()) return false;
                char x = st.top();
                if(it==')' && x=='(') st.pop();
                else if(it=='}' && x=='{') st.pop();
                else if(it==']' && x=='[') st.pop();
                else return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};