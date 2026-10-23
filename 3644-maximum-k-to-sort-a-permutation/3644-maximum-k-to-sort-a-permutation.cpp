class Solution {
public:
    int sortPermutation(vector<int>& arr) {
        int n = arr.size();        
        int ans =-1;
        for(int i=0; i<n; i++){
            if(arr[i]!=i){
                if(ans==-1) ans = arr[i];
                else ans = ans & arr[i];
            }
        }
        return ans==-1? 0 : ans;

    }
};