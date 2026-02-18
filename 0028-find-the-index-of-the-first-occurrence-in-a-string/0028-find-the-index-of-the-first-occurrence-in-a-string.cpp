class Solution {
public:
    vector<int>rabinKarpAlgo(string &a, string &b){
        // we using the hash function and rolling hash function to find the pattern --
        // hash = (a[0]*b^(m-1)+a[1]*b^(m-2)+....+a[n-1]*b^0)%mod
        // and rolling just remove the left most and add one in right        
        int n = a.size();
        int m = b.size();
        const int mod = 1e9+7;    // -- prime number
        const int base = 256;     // as 256 ascii characters
        long long highestPower = 1;    // base^m-1 --- m since patter size is m
        for(int i=0; i<m-1; i++){
            // base*base*base*... up to m-1 times
            highestPower = (highestPower*base)%mod;
        }

        long long patternHash = 0, stringHash = 0;
        // Initial hash for pattern and first window
        /* eg for ccb then it should be --
        h = c*B² + c*B¹ + b*B⁰
        for i = 0; patHash = (0*B+c) = c
        for i = 1; patHash = (c*B+c) = c*B+c
        for i = 2; patHash = ((c*B+c)*B+b) = c*B² + c*B¹ + b
        */
        for(int i=0; i<m; i++){
            // hash the patter(b) and the string(a)
            patternHash = (patternHash*base+b[i])%mod;
            stringHash = (stringHash*base+a[i])%mod;
        }

        vector<int>ans;

        for(int i=0; i<=n-m; i++){
            if(patternHash == stringHash){
                if(a.substr(i,m) == b){
                    ans.push_back(i);
                }
            }

            // rolling hash function --
            // Slide window
            /*  abcd and B = base
            (abc) H = a*B² + b*B¹ + c
            now for (bcd) we want -- b*B² + c*B¹ + d
            start from old hash = H = a*B² + b*B¹ + c (remove the leftmost)
            then = b*B¹ + c now if we add base(B) to it then => (b*B¹ + c) * B = b*B² + c*B¹
            and finally add d so b*B² + c*B¹ + d (we got the new hash without recalculating from the start)
            */
            if(i<n-m){
                // subtraction can make it -ve so +mod
                /*
                -30 % 101 = -30 (wrong) instead it is this: -30 mod 101 = 71
                and -30 ≡ 71 (mod 101) so (-30 + 101) % 101 => 71 % 101 => 71
                */
                stringHash = (stringHash - (a[i]*highestPower % mod) + mod) % mod;
                stringHash = ((stringHash*base)+a[i+m])%mod;
            }
        }

        return ans;
    }

    vector<int>kmpAlgo(string &a, string &b){
        int n = a.size();
        int m = b.size();

        // build lps for pattern --
        /*
        length of the longest proper prefix of pattern[0…i]
        that is also a suffix of pattern[0…i]
        *Proper prefix = cannot be the whole string.
        */
        vector<int>lps(m,0);
        int i = 1;
        int len = 0;
        while(i<m){
            if(b[i]==b[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }

        // pattern matching
        i=0;
        int j=0;
        vector<int>ans;
        while(i<n){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            if(j==m){
                // starting index will be i-m -- i++ and j++ already happned
                ans.push_back(i-m);
                j=lps[j-1];
            }

            else if(i<n && a[i]!=b[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }

    int findIndex(string &a, string &b){
        int n = a.size();
        int m = b.size();
        if(m>n) return -1;

        // -- also we can break when we find but here saving just for extra if asked find all
        vector<int>ans;
        // method 1 -- worst case o(n*m)
        /*
        for(int i=0; i<=n-m; i++){
            int j = 0;
            while(j<m && a[i+j]==b[j]) j++;
            if(j==m){
                ans.push_back(i);
            }
        }
        */

        // method 2 --- same o(n*m)
        /*
        for(int i=0; i<n-m; i++){            
            string t = a.substr(i, m);
            if(t==b){
                ans.push_back(i);
            }
        }
        */

        // method 3 --
        /*
        int res = a.find(b);
        if(res!=string::npos){
            return res;
        }
        else return -1;
        */


        // better method -- o(n+m) worst case o(n*m) --rabin karp algorithm
        // ans = rabinKarpAlgo(a,b);

        // best -- kmp and z function(dont know z function todo kmp)
        ans = kmpAlgo(a,b);

        return ans.empty()? -1 : ans[0];
    }

    int strStr(string haystack, string needle) {
        // brute --
        int firstIndex = findIndex(haystack, needle);
        return firstIndex;
    }
};