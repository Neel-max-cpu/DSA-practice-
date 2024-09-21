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
        // brute - 
        /*
        vector<string>v;
        for(int i=1; i<=n; i++){
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end());
        for(auto it:v){
            ans.push_back(stoi(it));
        }
        */

        // better - dfs
        /*
        for(char c = '1'; c<='9'; c++){
            // c string of len 1
            string s(1,c);
            helper(n, s, ans);
        }        
        return ans;
        */

        // iterative --
        int curr = 1;
        for(int i=1; i<=n; i++){
            ans.push_back(curr);
            if(curr*10<=n){
                curr = curr*10;
            }
            else{
                while(curr%10 ==9 || curr>=n) curr = curr/10;
                curr+=1;
            }
        }
        return ans;
    }
};