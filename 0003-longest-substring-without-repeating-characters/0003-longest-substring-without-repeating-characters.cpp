class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
         unordered_map<char,int>m;
        int ans = 0;
        int start = 0;
        
        /*
        for(int i=0; i<n; i++){
            char c = s[i];
            if(m.find(c)!=m.end()){
                // if found
                ans = max(ans, i-start);
                while(m.find(c)!=m.end()){
                    char x = s[start];
                    m.erase(x);
                    start++;
                }                
            }            
            m[c] = i;            
        }
        ans = max(ans, n-start);
        return ans;
        */
        
        // optimal --
        for(int i=0; i<n; i++){
            char c = s[i];
            if(m.find(c)!=m.end()){
                // cout<<i<<": "<<start<<", ";
                start = max(m[c]+1, start);
                // cout<<start<<endl;
            }
            m[c] = i;
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};