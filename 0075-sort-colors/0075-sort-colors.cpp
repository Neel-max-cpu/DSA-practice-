class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int start = 0, mid = 0, end = n-1;
        while(mid<=end){
            int x = arr[mid];
            if(x==0){
                swap(arr[start], arr[mid]);
                start++;
                mid++;                      
            }
            else if(x==2){
                swap(arr[mid], arr[end]);
                end--;
                //check mid again                
            }
            else if(x==1){
                mid++;
            }
        }
        
    }
};