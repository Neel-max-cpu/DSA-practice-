class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                int x = st.size();
                ans = max(x, ans);
                st.pop();
            }
        }
        return ans;
    }
};