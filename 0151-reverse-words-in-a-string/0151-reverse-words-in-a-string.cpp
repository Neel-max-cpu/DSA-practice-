class Solution {
public:
    string reverseWords(string s) {
        // string stream -- gfg https://www.geeksforgeeks.org/stringstream-c-applications/
        vector<string>words;
        stringstream ss(s);
        string word;

        while(ss>>word){
            words.push_back(word);
        }

        string ans ="";
        for(int i=words.size()-1; i>=0 ;i--){
            if(!ans.empty()){
                ans+=" ";
            }
            ans+=words[i];
        }
        return ans;
    }
};