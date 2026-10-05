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
        int ans = 0;
        // tle ---
        // method 1--
        /*
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                string t = s.substr(i,j-i+1);                
                if(valid(t)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        */

        // method 2 ---
        for(int i=0; i<s.size(); i++){
            int count = 0;
            for(int j=i; j<s.size(); j++){
                if(s[j]=='(') count++;
                else if(s[j]==')') count--;

                if(count<0) break;
                if(count == 0) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};