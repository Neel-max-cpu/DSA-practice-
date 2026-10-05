class Solution {
public:
    bool valid(string &s){
        if(s.size()%2==1) return false;

        int count = 0;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(c=='(') count++;
            else if(c==')') count--;

            if(count<0) return false;
        }
        return count==0;
    }
    int longestValidParentheses(string s) {
        int n = s.size();
        int ans = 0;
        // tle ---
        // method 1--
        /*
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string t = s.substr(i,j-i+1);                
                if(valid(t)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        */

        // method 2 ---
        /*
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=i; j<n; j++){
                if(s[j]=='(') count++;
                else if(s[j]==')') count--;

                if(count<0) break;
                if(count == 0) ans = max(ans, j-i+1);
            }
        }
        */

        // optimal ---
        stack<int>st;
        st.push(-1);
        for(int i=0; i<n; i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if (st.empty()) {
                    // current ")" is invalid - we are still pushing it though since for leng
                    // we do j-i+1 but since we are keeping 1 extra so j-i
                    st.push(i);
                }
                else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};