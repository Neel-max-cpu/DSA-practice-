class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right=n-1;
        int ans = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid]==target){
                ans = mid;
                return ans;
            }
            // check if left part is sorted --
            if(arr[left]<=arr[mid]){
                // check target is between
                if(target>=arr[left] && target<arr[mid]){
                    right = mid-1;
                }
                else left = mid+1;
            }
            // right part sorted --
            else{
                if(arr[mid]<target && target<=arr[right]){
                    left = mid+1;
                }
                else right = mid-1;
            }
        }
        return ans;
    }
};