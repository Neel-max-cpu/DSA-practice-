class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        // brute ---
        /*
        for(int i=0; i<n; i++){
            for(int j = i+1; j<=n; j++){
                string t = s.substr(i, j-i);
                unordered_map<char,int>m;
                for(auto it:t){
                    m[it]++;
                }
                int mini = 1e9, maxi = 0;
                for(auto it:m){
                    mini = min(it.second, mini);
                    maxi = max(it.second, maxi);
                }
                ans += (maxi-mini);
            }
        }
        return ans;
        */

        for(int i=0; i<n; i++){
            vector<int>freq(26,0);
            for(int j=i; j<n; j++){
                char ch = s[j];
                freq[ch-'a']++;
                int mini = 1e9;
                int maxi = 0;
                for(int k=0; k<26; k++){
                    if(freq[k]>0){
                        mini = min(freq[k], mini);
                        maxi = max(freq[k], maxi);
                    }
                }
                ans += (maxi-mini);
            }
        }
        return ans;

    }
};