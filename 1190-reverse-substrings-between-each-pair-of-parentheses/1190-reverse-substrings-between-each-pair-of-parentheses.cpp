class Solution {
public:
    string reverseParentheses(string s) {    
        int n = s.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int start = st.top();
                st.pop();
                reverse(s.begin()+start+1, s.begin()+i);
            }
        }

        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i]!='(' && s[i]!=')') ans+=s[i];
        }
        return ans;

        /*
        (ed(et(oc))el)
        (le((co)te)de)
        (le(et(oc))de)
        (le(et(co))de)
        */
    }
};




