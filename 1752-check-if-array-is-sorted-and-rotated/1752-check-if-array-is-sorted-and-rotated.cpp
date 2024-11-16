class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        // int rot = 0;
        // int mini = nums[0];
        // for(int i=1; i<n; i++){
        //     if(nums[i]<=mini){
        //         mini = nums[i];
        //         rot = i;
        //     }
        // }

        // vector<int>temp = nums;
        // sort(temp.begin(), temp.end());        
        // for(int i=0; i<n; i++){
        //     if(temp[i]!=nums[(i+rot)%n]) return false;
        // }
        // return true;

        int count = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1]>nums[i]) count++;
        }

        if(nums[n-1]>nums[0]) count++;
        return count<=1;
        
    }
};