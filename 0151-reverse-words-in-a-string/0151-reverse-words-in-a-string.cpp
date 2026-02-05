class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        stringstream ss(s);
        string word;
        while(ss >> word){
            v.push_back(word);
        }
        word = "";
        for(int i=v.size()-1; i>=0; i--){
            word+=v[i];
            word+=' ';
        }
        word.pop_back();
        return word;
    }
};