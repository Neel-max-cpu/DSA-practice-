class Solution {
public:

    bool findTarget(vector<int>&arr, int k){
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==k) return true;
            else if(arr[mid]<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size();
        int m = arr[0].size();
        /*
        for(int i=0; i<n; i++){
            int first = arr[i][0];
            int last = arr[i][m-1];
            if(first<=target && target<=last){
                return findTarget(arr[i], target);
            }
        }
        return false;
        */

        //optimal --
        int low = 0, high = (n*m)-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int i = mid/n;
            int j = mid%n;
            int x = arr[i][j];
            if(x==target) return true;
            else if(x<target){
                low = mid+1;
            }
            else high = mid-1;
        }
        return false;
    }
};