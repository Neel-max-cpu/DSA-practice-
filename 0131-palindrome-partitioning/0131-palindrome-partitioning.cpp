class Solution {
public:
    bool isValid(string &s, int start, int end){
       while(start<=end){
        if(s[start++]!=s[end--]) return false;
       }
       return true;
    }
    void helper(string &s, int start, vector<string>&temp, vector<vector<string>>&ans){
        if(start>=s.size()){                                    
            ans.push_back(temp);            
            return;
        }

        for(int i=start; i<s.size(); i++){
            if(isValid(s, start, i)){
                string x = s.substr(start, i-start+1);
                temp.push_back(x);
                helper(s, i+1, temp, ans);
                temp.pop_back();
            }
        }        
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        helper(s, 0, temp, ans);
        return ans;
    }
};