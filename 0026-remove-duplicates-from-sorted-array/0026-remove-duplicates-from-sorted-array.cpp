class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int l = 1, r=1;
        while(r<n){                        
            if(arr[r]!=arr[r-1]){
                arr[l] = arr[r];
                l++;
            }
            r++;
        }
        return l;
    }
};