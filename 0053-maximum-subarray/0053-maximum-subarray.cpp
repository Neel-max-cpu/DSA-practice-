class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int sum = 0, ans = INT_MIN;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            ans = max(sum, ans);
            if(sum<0) sum = 0;
        }
        return ans;
    }
};