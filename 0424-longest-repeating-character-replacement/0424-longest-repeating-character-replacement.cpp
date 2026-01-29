class Solution {
public:
    int ans = 0;
    void helper(string s, int k, char c, int mx, int i){
        if(i==s.size()){
            ans = max(mx, ans);
            return;
        }

        if(s[i]==c){
            helper(s, k, c, mx+1, i+1);
        }

        if(s[i]!=c){
            if(k>0){                            
                helper(s, k-1, c, mx+1, i+1);
            }
            else{
                ans = max(mx, ans);
                helper(s, k, c, 0, i+1);
            }
        }

    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        // o(n2)
        /*
        int ans = 0;
        for(int i=0; i<n; i++){
            int count = 1;
            int tempK=k;
            for(int j=i+1; j<n; j++){                
                if(s[i]==s[j] && i!=j) count++;
                else if(tempK>0){
                    count++;
                    tempK--;
                }
                else break;
            }
            ans = max(count, ans);
        }
        return ans;
        */

        /*
        aababba
        aaaa
        
        */       

        // recursion -- doesn't pass all tc
        /*
        for(int i=0; i<n; i++){
            helper(s, k, s[i], 0, 0);
        }
        return ans;
        */

        // o(n*26) ~ o(n)
        map<char,int>m;
        int ans = 0;
        int l=0, r=0;
        while(r<n){
            char c = s[r];
            if(m.find(c)!=m.end()){
                m[c]++;
            }
            else m[c] = 1;

            // most freq char
            int maxi = 0;
            for(auto it:m){
                maxi = max(maxi, it.second);
            }
            // size of the window
            int size = r-l+1;
            
            // if valid
            if(size-maxi<=k){
                cout<<l<<" "<<r<<": ";
                ans = max(ans, size);
                cout<<ans<<endl;
            }
            else{
                m[s[l]]--;
                l++;
            }            
            r++;
        }
        return ans;
        




        /*
        aababba
        a a a a ans = max(3-0+1)
        

        */

       
    }
};