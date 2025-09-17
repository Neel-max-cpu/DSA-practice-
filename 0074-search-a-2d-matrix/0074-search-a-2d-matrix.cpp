class Solution {
public:


    bool binary_best(vector<vector<int>>&v, int low, int high, int row, int col, int target){

        while(low<=high){
            int mid = low+(high-low)/2;

            // now convert the ele into index
            int r = mid/col;
            int c = mid%col;
            if(v[r][c] == target){
                return true;
            }
            else if(v[r][c] < target){
                low = mid+1;
            }
            else high = mid-1;
        }
        return false;
    }

    bool searchBinary(const vector<vector<int>>& matrix, int row, int columns, int target) {
        int left = 0;
        int right = columns - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target) {
                return true;  // Element found
            } else if (matrix[row][mid] < target) {
                left = mid + 1;  // Search in the right half
            } else {
                right = mid - 1;  // Search in the left half
            }
        }

        return false;  // Element not found
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
        for(int i=0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[i].size(); j++){
                if(matrix[i][j]== target) return true;
            }
        }
        return false;
        */

        /*
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0;
        while(i<n){
            if(matrix[i][0]<=target){
                // search in the row
                for(int j=0; j<m; j++){
                    if(matrix[i][j]==target){
                        return true;
                    }
                }
                i++;
            }
            else{
                i++;
            }
        }
        return false;
        */


         // better ---
         /*
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){
                // search in the row
                bool found  = searchBinary(matrix, i, m, target);
                if(found) return true;
            }
        }
        return false;
        */

        // best --- think it like a 1d array which is sorted
        int n = matrix.size();
        int m = matrix[0].size();
        int last_ind = n*m - 1;
        bool found = binary_best(matrix, 0,last_ind, n, m, target);
        return found;
    }
};