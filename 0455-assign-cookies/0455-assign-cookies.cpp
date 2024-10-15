class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // brute ---
        /*
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());        
        int count = 0;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<s.size(); j++){
                if(s[j]==-1) continue;
                if(s[j]>=g[i]) {
                    count++;
                    s[j] = -1;
                    break;
                }
            }
        }
        return count;
        */

        // better ---
        /*
        if(g.size()==0 || s.size()==0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0, j = 0;        
        if(g[i]>s[s.size()-1]) return 0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                count++;
                j++;
                i++;
            }
            else if(s[j]<g[i]) j++;
        }
        return count;
        */

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size(), m = s.size();
        int l = 0, r = 0;
        while(l<m && r<n){
            if(g[r]<=s[l]) r++;
            l++;
        }        
        return r;



    }
};