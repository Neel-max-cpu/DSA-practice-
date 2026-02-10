class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i=0; i<strs.size(); i++){
            if(i==0) {
                ans = strs[i];
                // cout<<ans<<" "<<i<<endl;
            }
            else{
                string temp = "";
                int j = 0;
                int k = 0;
                while(k<ans.size() && j<strs[i].size()){
                    if(strs[i][j]==ans[k]){
                        k++;
                        j++;
                    }
                    else break;
                }
                ans.erase(k, ans.size()-k);
                if(ans.size()==0) return ans;
                // cout<<ans<<" "<<i<<endl;                
            }
        }
        return ans;
    }
};