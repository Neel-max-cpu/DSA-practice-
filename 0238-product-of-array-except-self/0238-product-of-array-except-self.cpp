class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);

        // brute --
        /*
        vector<int>pre(n,1);
        vector<int>suf(n,1);
        long long pro = 1;
        for(int i=0; i<n; i++){
            pro = nums[i]*pro;
            pre[i]=pro;
        }
        pro = 1;
        for(int i=n-1; i>=0; i--){
            pro = nums[i]*pro;
            suf[i] = pro;
        }

        for(int i=0; i<n; i++){
            if(i==0) ans[i] = suf[i+1];
            else if(i==n-1) ans[i]=pre[i-1];
            else ans[i] = pre[i-1]*suf[i+1];
        }
        */
        // best --
        int prefix = 1;
        for(int i=0; i<n; i++){
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for(int i=n-1; i>=0; i--){
            ans[i] = ans[i]*suffix;
            suffix *= nums[i];
        }        

        return ans;
    }
};