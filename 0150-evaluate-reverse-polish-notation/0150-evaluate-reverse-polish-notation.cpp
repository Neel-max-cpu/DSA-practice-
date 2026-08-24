class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<int>st;
        for(auto it:arr){
            if(it=="+" || it=="-" || it=="*" || it=="/"){
                int two = st.top();
                st.pop();
                int one = st.top();
                st.pop();
                int val;
                if(it=="+"){
                    val = one+two;
                }
                if(it=="-"){
                    val = one-two;
                }
                if(it=="*"){
                    val = one*two;
                }
                if(it=="/"){
                    val = one/two;
                }
                st.push(val);
            }
            else st.push(stoi(it));
        }
        return st.top();
    }
};