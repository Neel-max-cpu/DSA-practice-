class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        for(auto it:strs){
            string s = it;
            sort(s.begin(), s.end());
            m[s].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};