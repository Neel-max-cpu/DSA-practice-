class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(mini>arr[i]) mini = arr[i];
            else{
                ans = max(ans, arr[i]-mini);
            }
        }
        return ans;
    }
};