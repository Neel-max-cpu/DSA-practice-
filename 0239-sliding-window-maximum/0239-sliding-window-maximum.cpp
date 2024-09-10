class Solution {
public:
    int check(vector<int>&nums, int start, int end){
        int maxi = INT_MIN;
        for(int i=start; i<end; i++){
            maxi = max(nums[i], maxi);
        }
        return maxi;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        // brute force ---
        /*
        vector<int>ans;
        for(int l=0; l<n-k+1; l++){            
            ans.push_back(check(nums, l, l+k));    
        }
        return ans;
        */
        
        vector<int>ans;
        // keep the deque in decreasing order always
        deque<int>dq;
        int l = 0, r=0;
        while(r<n){
            while(!dq.empty() && nums[dq.back()]<nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);

            if(l>dq.front()) dq.pop_front();
            if(r+1>=k) {
                ans.push_back(nums[dq.front()]);
                l++;
            }
            r++;
        }
        return ans;
        
        
        
    }
};