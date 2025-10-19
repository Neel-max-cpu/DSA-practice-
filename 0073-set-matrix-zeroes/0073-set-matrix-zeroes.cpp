class Solution {
public:    
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int col0 = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==0){ 
                   //mark it in the ith row
                    arr[i][0] = 0;
                    if(j!=0){
                        // mark it in the jth row
                        arr[0][j] = 0;
                    }
                    else col0 = 0;
                }
            }
        }      

        //make the whole except 1st row/col
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(arr[i][j]!=0){
                    if(arr[0][j]==0 || arr[i][0]==0){
                        arr[i][j] = 0;
                    }
                }
            }
        }

        //then change the 1st row ---
        if(arr[0][0]==0){
            for(int j=0; j<m; j++){
                arr[0][j] = 0;
            }
        }
        //then change the 1st col ---
        if(col0==0){
            for(int i=0; i<n; i++){
                arr[i][0] = 0;
            }
        }

    }
};