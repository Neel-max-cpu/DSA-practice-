class Solution {
public:
    string frequencySort(string s) {
        map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        vector<pair<char,int>>v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](const pair<char,int>&a, const pair<char,int>&b){
            if(a.second==b.second) return a.first<b.first;
            return a.second>b.second;
        });

        string ans = "";
        for(auto it:v){
            ans.append(it.second, it.first);
        }
        return ans;
    }
};