class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int maxVal = arr[0];
        int ans = maxVal;
        int sum = maxVal;
        for(int i=1; i<n; i++){           
           //single element could be ans
           maxVal = max(maxVal, arr[i]); 
           if(sum<0){
                sum = 0;
           }
           
           sum += arr[i];
           ans = max(ans, sum);
        }
        cout<<sum<<" "<<maxVal<<" "<<ans<<endl;
        return max(ans,max(maxVal, sum));
    }
};