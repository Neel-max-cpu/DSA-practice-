class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            // This condition ensures that the left part is sorted
            if(nums[low]<=nums[mid]){
                // in the left half -- it signifies that the target is in this sorted left half. So, we will eliminate the right half 
                if(nums[low]<=target && target<=nums[mid]) high = mid-1;
                // in the right half
                else low = mid+1;
            }
            else{
                // in the right half --  It signifies that the target is in this sorted right half. So, we will eliminate the left half
                if(nums[mid]<=target && target<=nums[high]) low = mid+1;
                // in the left half
                else high = mid-1;
            }
        }
        return -1;



        // brute
        /*
        for(int i=0; i<n; i++){
            if(nums[i]==target) return i;
        }
        return -1;
        */
    }
};