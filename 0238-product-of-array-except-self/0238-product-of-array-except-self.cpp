class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // post
        vector<int>a;
        // pre
        vector<int>b(n);

        int x = 1;
        int y = 1;
        for(auto it:nums){
            x*=it;
            a.push_back(x);
        }

        for(int i=n-1; i>=0; i--){
            y*=nums[i];
            b[i] = y;
        }

        vector<int>ans(n);
        for(int i=0; i<n; i++){
            if(i==0)
                ans[i] = b[i+1];
            else if(i==n-1)
                ans[i] = a[i-1];
            else{
                int temp = a[i-1]*b[i+1];
                ans[i] = temp;
            }
        }   
        return ans;
        
    }
};