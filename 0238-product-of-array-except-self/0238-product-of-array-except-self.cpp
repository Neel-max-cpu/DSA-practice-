class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // METHOD 2 ---
        int pre = 1;
        vector<int>ans(n,1);
        for(int i=0; i<n; i++){
            ans[i] = pre;
            pre = pre*nums[i];
        }
        int post = 1;
        for(int i=n-1; i>=0; i--){
            ans[i] = ans[i]*post;
            post = post*nums[i];
        }
        return ans;



        // METHOD 1---
        /*
        // post, pre                
        vector<int>a, b(n);
        int x = 1;
        int y = 1;
        // n
        for(auto it:nums){
            x*=it;
            a.push_back(x);
        }
        // n
        for(int i=n-1; i>=0; i--){
            y*=nums[i];
            b[i] = y;
        }
        // n
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            if(i==0) ans[i] = b[i+1];
            else if(i==n-1) ans[i] = a[i-1];
            else{
                int temp = a[i-1]*b[i+1];
                ans[i] = temp;
            }
        }   
        return ans;
        */
        
    }
};