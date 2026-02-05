class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m;
        m['I'] = 1;        
        m['V'] = 5;        
        m['X'] = 10;        
        m['L'] = 50;        
        m['C'] = 100;        
        m['D'] = 500;        
        m['M'] = 1000;

        int ans = 0;
        int n = s.size();
        int i = n-1;
        ans += m[s[i]];
        i--;
        while(i>=0){                                    
            // check the next one
            int one = m[s[i]];
            int next = m[s[i+1]];
            if(next>one) ans-=m[s[i]];
            else ans+=m[s[i]];
            i--;                    
        }
        return ans;
    }
};