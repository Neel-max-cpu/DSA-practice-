class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1;
        int ans = 1e9;
        while(left<=right){
            int mid = (left+right)/2;
            // check for left sorted
            if(arr[left]<=arr[mid]){
                // take the min in the left
                ans = min(ans, arr[left]);
                // and go to right part
                left = mid+1;
            }
            else{
                // take the min in the right
                ans = min(ans, arr[mid]);
                // and go to left part
                right = mid-1;
            }
        }
        return ans;
        
    }
};