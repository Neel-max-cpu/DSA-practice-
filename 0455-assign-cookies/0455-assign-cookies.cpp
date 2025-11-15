class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int n = g.size();
        
        int j = 0;
        int m = s.size();

        for(int i=0; i<n; i++){
            if(j>=m) break;
            else{
                while(j<m){
                    if(g[i]<=s[j]) {
                        ans++;
                        j++;
                        break;
                    }
                    else j++;
                }
            }
        }
        return ans;
    }
};