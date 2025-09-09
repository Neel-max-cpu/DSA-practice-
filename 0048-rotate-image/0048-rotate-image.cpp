class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();

        //transpose in place 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                else if(i<j){
                    swap(arr[i][j], arr[j][i]);
                }
            }
        }       

        //reverse each row
        for(int i=0; i<n; i++){
            reverse(arr[i].begin(), arr[i].end());
        }
    }
};