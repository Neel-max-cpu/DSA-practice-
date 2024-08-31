class Solution {
public:
    string stringHash(string s, int k) {
        string ans = "";
        for(int i=0; i<s.size(); i+=k){
            int sum = 0;
            for(int j=i; j<i+k; j++){
                char c = s[j];                                
                sum += c-'a';                
            }
            // cout<<i<<" "<<sum<<endl;
            sum = sum%26;            
            ans += ('a'+sum);            
        }        
        return ans;
    }

};