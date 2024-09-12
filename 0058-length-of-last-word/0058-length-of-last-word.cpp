class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string>v;
        stringstream ss(s);
        string word;
        while(ss>>word)
            v.push_back(word);

        string t = v[v.size()-1];
        return t.size();
    }
};