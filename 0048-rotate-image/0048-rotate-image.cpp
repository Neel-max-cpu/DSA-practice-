#include<vector>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        /*
        vector<vector<int>>ans;
        for(int j=0; j<n; j++){
            vector<int>temp;
            for(int i=n-1; i>=0; i--){
                temp.push_back(matrix[i][j]);
            }
            ans.push_back(temp);
        }
        */
        // another way both brute force
        /*
        vector<vector<int>>ans(n, vector<int>(n,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int k = (n-1)-i;
                ans[j][k] = matrix[i][j];
            }
        }

        for(int i = 0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                matrix[i][j] = ans[i][j];
            }
        }
        */

        // optimal approach -- transpose the matrix and then reverse each row

        // transpose ---         
        /*
        [a b c]   ->  [a d]
        [d e f]       [b e]
                      [c f]

        eg1 
        [1,2,3] -> [1,4,7]
        [4,5,6]    [2,5,8]
        [7,8,9]    [3,6,9]

        reverse each row

        [1,4,7] ->  [7,4,1]
        [2,5,8]     [8,5,2]
        [3,6,9]     [9,6,3]
                        
        
        
        */
        // o(n*n)
        // transpose
        /*
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        */

        // better way 
        for(int i=0; i<n; i++){
            for(int j=0; j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row
        //o(n*n)
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        
    }
};