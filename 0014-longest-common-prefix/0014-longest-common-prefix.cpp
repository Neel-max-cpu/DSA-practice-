class Solution {
public:
    string compare(string &one, string &two){
        int n = one.size();
        int m = two.size();
        int len = min(n, m);
        
        int i = 0;
        for(i=0; i<len; i++){            
            if(one[i]!=two[i]) break;
        }
        
        // similar from 0 to i-1
        if(i==len){
            // just for better tc since substring creation is o(k) where k = len
            if(n>m) return two;
            else return one;
        }     
        else{
            return one.substr(0, i);
        }   
    }

    string longestCommonPrefix(vector<string>& arr) {
        int n = arr.size();

        // vertical scaning ---
        /*
        int minLen = INT_MAX;
        for(int i=0; i<n; i++){
            int l = arr[i].size();
            minLen = min(l, minLen);
        }

        int j=0;
        string s ="";
        char c = arr[0][j];
        while(j<minLen){
            for(int i=1; i<n; i++){
                if(arr[i][j]!=c) return s;
            }
            s+=c;
            j++;
            if(j<minLen)
                c = arr[0][j];
        }
        return s;
        */

        // horizontal scaning --- assume first string is the prefix
        string ans = arr[0];
        for(int i=1; i<n; i++){            
            string val = compare(ans, arr[i]);
            ans = val;
        }
        return ans;

    }
};