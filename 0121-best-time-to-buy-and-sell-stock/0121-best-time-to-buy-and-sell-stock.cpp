class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        /*
        int ans = 0;
        for(int i=0; i<n; i++){
            int val = 0;
            for(int j=i+1; j<n; j++){
                val = max(val, arr[j]-arr[i]);
            }
            ans = max(ans, val);
        }
        return ans;
        */

        int ans = 0;
        int val = arr[0];
        for(int i=1; i<n; i++){
            if(val>arr[i]){
                //then buy that day
                val = arr[i];
            }
            else{
                ans = max(ans, arr[i]-val);
            }
        }
        return ans;
    }
};