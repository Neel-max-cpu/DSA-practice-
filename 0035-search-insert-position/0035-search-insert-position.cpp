class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        

        // basically lower bound;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]==target) return mid;
            
            else if(nums[mid]>target){
                end = mid-1;
            }
                
            else if(nums[mid]<target){
                start = mid+1;
            }
        }
        return start;                
    }
};