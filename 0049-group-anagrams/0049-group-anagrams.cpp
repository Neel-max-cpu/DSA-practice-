class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        // better --
        /*
        for(auto it:strs){
            string s = it;
            sort(s.begin(), s.end());
            m[s].push_back(it);
        }
        */

        // best to avoid sort --
        for(auto it:strs){
            vector<int>count(26,0);
            for(auto x:it){
                count[x-'a']++;
            }
            string key = to_string(count[0]);
            for(int i=1; i<26; i++){
                key += ','+to_string(count[i]);
            }
            // here we skipped the sorting (from better)--
            /*
            eg it = eat
            then vector<int>count would be --
            [1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0]
            and then key would be == 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0
            so we can direclty put the key in map and check each time and is better than sorting
            */
            m[key].push_back(it);
        }
        vector<vector<string>>ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};