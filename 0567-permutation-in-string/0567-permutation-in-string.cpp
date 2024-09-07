class Solution {
public:

    void helper(vector<string>&v, string s){
        sort(s.begin(), s.end());
        do{
            v.push_back(s);
        }while(next_permutation(s.begin(), s.end()));
    }    

    bool isPermutation(vector<int>&m){
       for(int i=0; i<26; i++){
        if(m[i]!=0) return false;
       }
       return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        // brute - o(n*n!)+o((s2.size()-s1.size()+1)*n!)
        /*
        vector<string>v;
        helper(v, s1);
        int l=0, len = s1.size();
        while(l+len-1<s2.size()){
            string t = s2.substr(l, len);
            for(auto it:v){
                if(it==t) return true;
            }
            l++;            
        }
        return false;
        */

        // tc = o(n)+o((s2.size()-s1.size()+1)+o(2*t.size))  v.bad tc (XD)
        /*
        map<char,int>m1;
        for(auto it:s1){
            m1[it]++;
        }
        int l=0, len = s1.size();
        while(l+len-1<s2.size()){
            map<char,int>m;
            string t = s2.substr(l, len);
            for(auto it:t){
                m[it]++;
            }
            
            int f = 0;
            for(int i=0; i<t.size(); i++){
                char c = t[i];
                if(m1.find(c)!=m1.end()){
                    if(m1[c]!=m[c]) {
                        f = 1;
                        break;
                    }
                }
                else{
                    f = 1;
                    break;                
                } 
            }        
            if(f==0)    
                return true;
            l++;
        }
        return false;
        */  

        // o(26*n) ~ o(n)
        /*
        int n1 = s1.size();
        int n2 = s2.size();
        vector<int> m(26);
        for(int i=0; i<n1; i++){
            m[s1[i]-'a']++;        
            m[s2[i]-'a']--;        
        }
        // for(auto it:m) cout<<it<<" ";
        // cout<<endl;
        if(isPermutation(m)) return true;

        for(int i=n1; i<n2; i++){
            m[s2[i]-'a']--;
            m[s2[i-n1]-'a']++;
            // for(auto it:m) cout<<it<<" ";
            // cout<<endl;
            if(isPermutation(m)) return true;
        }
        return false;
        */

        // o(n1+n2)
        int n1 = s1.size();
        int n2 = s2.size();
                
        if (n1 > n2) return false;        
        vector<int> m1(26, 0), m2(26, 0);        
        for (int i = 0; i < n1; i++) {
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }        
        if (m1 == m2) return true;
    
        for (int i = n1; i < n2; i++) {
            m2[s2[i] - 'a']++;            
            m2[s2[i - n1] - 'a']--;            
            if (m1 == m2) return true;
        }
        return false;

    }
};