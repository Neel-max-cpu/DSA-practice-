class Solution {
public:
    string getString(string a, int mul){
        string ans;
        for(int i=1; i<=mul; i++){            
            ans += a;
        }
        return ans;
    }

    unordered_map<string,int>findSubstr(string s){
        int n = s.size();
        unordered_map<string,int>m;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string temp = s.substr(i, j-i+1);
                m[temp]++;
            }
        }
        return m;
    }

    void print(unordered_map<string,int>m, int i, string s){
        cout<<"for i: "<<i<<" string: "<<s<<endl;
        for(auto it:m) cout<<it.first<<" ";
        cout<<endl;
        cout<<endl;
    }

    bool kmpAlgo(string &a, string &b){
        int n = a.size(), m = b.size();
        vector<int>lps(m,0);
        int len = 0;
        int i = 1;

        // build lps ---
        /*
        dry run
        string b = ababcabab and a = bababababcababcabab 
        */
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
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // pattern matching ---
        i = 0;
        int j=0;
        while(i<n){
            if(a[i]==b[j]){
                i++;
                j++;
            }

            // pattern found -- where returning all the index found then when j>=m there do j = lps[m-1]
            // here at first place we found all we return true
            // and j==m found at index (i-m) since both j&i incremented (and i==m)
            if(j==m) return true;
            else if(i<n && a[i]!=b[j]){
                if(j!=0){
                    j = lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
    }

    bool findSubstring(string &a, string &b){
        int n = a.size(), m = b.size();
        // tc - o(n*m) = o(m2) since n = m or m+1
        /*
        for(int i=0; i<n; i++){
            string temp = a.substr(i, m);
            if(temp == b) return true;
        }        
        return false;
        */

        // better -- still o(m2) but sc = o(1)
        /*
        for(int i=0; i<n; i++){
            int j = 0;
            while(j<m && a[i+j]==b[j]) j++;
            if(j==m) return true;
        }
        return false;
        */

        // using find--
        /*
        int find = a.find(b);
        if(find != string::npos) return true;        
        else return false;
        */

        // best --
        if(kmpAlgo(a,b)) return true;
        else return false;

    }

    int repeatedStringMatch(string a, string b) {

        // very brute -- o(i*n) + o(n3) + find o(1) + loop o(100) to compute O((i*n)³) or o(n3)
        /* 
        unordered_map<string,int>m;

        for(int i=1; i<=100; i++){
            string temp = getString(a, i);            
            m =  findSubstr(temp);        
            // print(m, i, temp);
            if(m.find(b)!=m.end()){
                return i;
            }
        }
        return -1;
        */

        // better -- tc - o(n*i) + o(n3) + o(1) and loop for o(2) = k,k+1 so overall o(n3) still 
        /*
        int n = a.size(), m = b.size();
        // if b is going to fit inside a then n>=m; and ceil will give that
        int k = ceil((double)m/n);
        // Repeat string(a) k times; now Check if b is substring
        // If not, repeat once more (k+1) and check if present then yes else return -1
        unordered_map<string,int>map;
        for(int i=k; i<=k+1; i++){
            // why i+1 cause i am resuing the function from before(:)) ---
            string temp = getString(a, i);            
            map = findSubstr(temp);
            if(map.find(b)!=map.end()){
                return i;
            }
        }
        return -1;
        */

        // better/best --- same as above just not creating the substring      
        // tc - main lop 2 times(k,k+1) + getstring(n*i)~(n*(m/n))~o(m)[since i = ceil of m/n] + 
        // findSubstringo(n*m) so o(2)+o(m)+o(n*m) and n==m or m+1 so o(m*m) = o(m2) 
        int n = a.size(), m = b.size();
        // if b is going to fit inside a then n>=m; and ceil will give that
        int k = ceil((double)m/n);
        // Repeat string(a) k times; now Check if b is substring
        // If not, repeat once more (k+1) and check if present then yes else return -1        
        for(int i=k; i<=k+1; i++){
            // why i+1 cause i am resuing the function from before(:)) ---
            string temp = getString(a, i);            
            if(findSubstring(temp, b)){
                return i;
            }        
        }
        return -1;


    }
};