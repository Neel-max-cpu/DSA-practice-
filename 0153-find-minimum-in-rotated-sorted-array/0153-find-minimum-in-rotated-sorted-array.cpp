class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1;
        int ans = min(arr[left], arr[right]);
        while(left<=right){
            // if at any point the array is sorted --
            if(arr[left]<=arr[right]){
                ans = min(ans, arr[left]);
                return ans;
            }
            int mid = left + (right-left)/2;
            if(arr[mid]>=arr[right]){
                // go right side - since we need to find min
                ans = min(ans, arr[mid]);
                left = mid+1;
            }
            else{
                // if mid is not greater than right then stay left
                ans = min(ans, arr[mid]);
                right = mid-1;
            }            
        }
        return ans;
    }
};