class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        /*
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i]!=i) return i;
        }
        return n;
        */

        vector<int>v(n+1,-1);
        for(int i=0; i<n; i++){
            v[nums[i]] = 1;
        }

        for(int i=0; i<n+1; i++){
            if(v[i]==-1) return i;
        }
        // temp return
        return -1;
    }
};