class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // brute force 
        /*
        int ans = -1e9;
        for(int i=0; i<n; i++){
            int pro = 1;
            // cout<<i<<": ";
            for(int j=i; j<n; j++){
                pro*=nums[j];
                // cout<<pro<<" ";
                ans = max(ans, pro);
            }
            // cout<<endl;
        }
        return ans;
        */

        int pre = 1, suff = 1;
        int ans = -1e9;
        for(int i=0; i<n; i++){
            if(pre==0) pre = 1;
            if(suff==0) suff = 1;
            pre *= nums[i];
            suff *= nums[n-1-i];
            ans = max({ans, pre, suff});
        }
        return ans;
    }
};