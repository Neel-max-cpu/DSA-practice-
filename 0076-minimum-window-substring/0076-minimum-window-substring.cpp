class Solution {
public:
    bool isValid(unordered_map<char,int>&ms, unordered_map<char,int>&mt){
        for(auto it:mt){
            char c= it.first;
            if(ms.find(c)==ms.end()) return false;
            else{
                if(ms[c]<it.second) return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        int n = s.size();
        unordered_map<char,int>mt;
        for(auto it:t) mt[it]++;
        unordered_map<char,int>ms;

        // brute --
        /*

        int left = 0, right = 0;
        string ans="";
        while(right<n){
            char c = s[right];
            ms[c]++;

            // if valid keep shrinking             
            while(left<=right && isValid(ms, mt)){
                // could be ans
                string temp = s.substr(left, right-left+1);
                if(ans=="") ans = temp;
                else if(ans!="" && ans.size()> temp.size()){
                    ans = temp;
                }

                char x = s[left];
                ms[x]--;
                if(ms[x]==0) ms.erase(x);
                left++;
            }

            right++;
        }        
        return ans;
        */

        // optimal --- here same as above just changing isValid
        int have = 0;
        int need = mt.size();    // distinct characters from t
        int left = 0;

        int resLen = INT_MAX;
        int res[2]={-1,-1};

        for(int right = 0; right<s.size(); right++){
            char c = s[right];
            ms[c]++;
            // if char c is present in t and freq is atleast equal then we have
            if(mt.count(c) && ms[c]==mt[c]){
                //  ms[c]==mt[c] since we are counting distinct not how may character so freq should be >= but not less so we are doing ==
                have++;
            }

            while(have == need){
                // when window is valid
                int len = right-left+1;
                if(len < resLen){
                    resLen = len;
                    res[0] = left;
                    res[1] = right;
                }

                // shrink till valid
                char x = s[left];
                ms[x]--;
                if(mt.count(x) && ms[x]<mt[x]){
                    have--;
                }
                left++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res[0], resLen);
    }
};