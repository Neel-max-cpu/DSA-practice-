class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>m;
        for(auto it:knowledge){
            string key = it[0];
            string value = it[1];
            m[key]=value;
        }

        string ans;
        for(int i=0; i<s.size(); i++){
            if(s[i]!='('){
                ans+=s[i];
                continue;
            }

            // s[i]=='('
            int j = i+1;
            while(s[j]!=')'){
                j++;
            }
            int pos = i+1;
            int len = j-pos;
            string key = s.substr(pos, len);

            if(m.find(key)!=m.end()){
                ans+=m[key];
            }
            else ans+='?';

            i=j;
        }
        return ans;                
    }
};