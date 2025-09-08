class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j=n-1, k = n/2;        
        while(k<=j){
            if(arr[i]==0) {
                i++;
            }
            else if(arr[i]==2){
                swap(arr[i], arr[j]);
                j--;                
            }
            else if(arr[i]==1){
                swap(arr[i], arr[k]);
                k++;
                i++;
            }
        }
    }
};