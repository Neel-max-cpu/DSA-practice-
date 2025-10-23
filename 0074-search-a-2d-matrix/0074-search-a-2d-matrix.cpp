class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int m = arr.size();
        int n = arr[0].size();
        int low = 0, high = m*n-1;

        // we could do mid/m and mid%m if it were column wise sorted(but here its row wise)
        while(low<=high){
            // int mid = (low+high)/2;
            int mid = low + (high-low)/2;
            int midRow = (mid/n);
            int midCol = (mid%n);
            if(target == arr[midRow][midCol]){
                return true;
            }
            else if(target>arr[midRow][midCol]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};