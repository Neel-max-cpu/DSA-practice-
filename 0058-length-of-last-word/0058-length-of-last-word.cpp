class Solution {
public:
    int lengthOfLastWord(string s) {
        // brute --
        /*
        vector<string>v;
        stringstream ss(s);
        string word;
        while(ss>>word)
            v.push_back(word);

        string t = v[v.size()-1];
        return t.size();
        */

        // optimal
        stringstream ss(s);
        string word;
        int last= 0;
        while(ss>>word){
            last = word.size();
        } 
        return last;
    }
};