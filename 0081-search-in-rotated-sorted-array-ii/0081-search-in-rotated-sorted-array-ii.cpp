class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid]==target) 
                return true;
            // since elements can be repeated so edge case arr[left]==arr[mid]==arr[right];
            if((arr[left]==arr[mid]) && (arr[mid]==arr[right])){
                // edge case  eliminate them won't change the search space 
                left++;
                right--;
                continue;
            }
            // rest stays the same
            // check if left is sorted
            if(arr[left]<=arr[mid]){
                // left is sorted then check target lies in the sorted half or not
                if(arr[left]<=target && target<=arr[mid]) right = mid-1;
                else left = mid+1;
            }
            else{
                // right is sorted then check target lies in the sorted half or not
                if(arr[mid]<=target && target<=arr[right]) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};