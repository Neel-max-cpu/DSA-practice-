class Solution {
public:
    void helper(int n, string &s, vector<int>&ans){
        int x = stoi(s);
        if(x>n) return;
        ans.push_back(x);
        for(char c = '0'; c<='9'; c++){
            s.push_back(c);
            int y = stoi(s);
            if(y<=n) helper(n, s, ans);
            s.pop_back();
        }   
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;       
        for(char c = '1'; c<='9'; c++){
            // c string of len 1
            string s(1,c);
            helper(n, s, ans);
        }
        return ans;
    }
};