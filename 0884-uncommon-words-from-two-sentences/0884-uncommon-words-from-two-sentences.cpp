class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        // brute --
        // /*
        unordered_map<string,int>m;
        stringstream ss(s1);
        string s;
        while(ss>>s){
            m[s]++;
        }
        stringstream ss1(s2);
        while(ss1>>s){
            m[s]++;
        }
        vector<string>v;
        for(auto it:m){
            if(it.second==1) v.push_back(it.first);
        }    
        return v;
        // */
    }
};