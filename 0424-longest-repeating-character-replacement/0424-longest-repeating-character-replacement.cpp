class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        // brute --
        /*
        for(int i=0; i<n;i++){
            char c = s[i];
            int temp = k;
            int count = 1;
            for(int j=i+1; j<n; j++){
                if(s[j]==c) {
                    count++;
                }
                else if(s[j]!=c && temp > 0){
                    count++;
                    temp--;
                }    
                else{
                    break;
                }            
            }
            ans = max(count, ans);
        }
        return ans;
        */


        unordered_map<char,int>m;                
        int maxFreq=0;
        int left = 0;
        for(int right = 0; right<n; right++){
            char c = s[right];
            // freq increase
            m[c]++;

            maxFreq = max(maxFreq, m[c]);
            /*
                windowSize = right-left+1;
                basically window is valid if windowsize - maxFreq <= k
                why :
                ababba and k = 2
                let l = 0 and r=1 so in map a=1, and b=1 and windowsize = r-l+1 = 2
                and maxFreq = 1 so 2-1 = 1(number of replacements we have to make) which is <=k so valid
                
                if not valid then while loop(below)
            */
            while((right-left+1)-maxFreq > k){
                m[s[left]]--;
                left++;
            }
            ans = max(right-left+1, ans);
        }
        return ans;
    }
};