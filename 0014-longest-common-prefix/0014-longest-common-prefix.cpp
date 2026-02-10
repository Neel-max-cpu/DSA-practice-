class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n = arr.size();

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
            c = arr[0][j];
        }
        return s;
    }
};