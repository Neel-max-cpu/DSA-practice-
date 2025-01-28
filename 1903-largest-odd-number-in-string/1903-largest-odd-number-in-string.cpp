class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.size();
        string ans = "";
        for(int i=n-1; i>=0; i--){
            int x = s[i];
            if(x%2==1){
                ans = s.substr(0,i+1);
                return ans;
            }
            else continue;
        }
        return ans;
    }
};