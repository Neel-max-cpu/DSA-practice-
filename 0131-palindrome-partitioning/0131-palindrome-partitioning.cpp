class Solution {
public:
    bool check(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

    void helper(string s, vector<vector<string>>&ans, vector<string>&temp, int idx){
        if(idx==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            //first part i.e idx to i is palindrom or not if yes
            //partition is possible
            if(check(s, idx, i)){
                // from idx to i is a valid substr - substr(pos, len)
                string x = s.substr(idx, i-idx+1);                
                temp.push_back(x);
                helper(s, ans, temp, i+1);                     
                temp.pop_back();
            }            
        }        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        helper(s, ans, temp, 0);
        return ans;
    }
};