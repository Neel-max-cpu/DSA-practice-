class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='[') st.push(it);
            else if(it==')'){
                if(st.empty()) return false;
                char c = st.top();
                if(c=='(') st.pop();
                else return false;
            }
            else if(it=='}'){
                if(st.empty()) return false;
                char c = st.top();
                if(c=='{') st.pop();
                else return false;
            }
            else if(it==']'){
                if(st.empty()) return false;
                char c = st.top();
                if(c=='[') st.pop();
                else return false;
            }
        }
        return st.empty() ? true : false;
    }
};