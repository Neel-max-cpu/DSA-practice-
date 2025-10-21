class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int sum = arr[0];
        int ans = arr[0];
        for(int i=1; i<n; i++){
            // each step we start fresh or drag on
            sum = max(arr[i], sum+arr[i]);
            ans = max(sum, ans);
        }
        cout<<sum<<" "<<ans<<endl;
        return ans;
    }
};