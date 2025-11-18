class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int breakPoint = -1;
        for(int i=n-1; i>=1; i--){
            if(arr[i]>arr[i-1]){
                breakPoint = i-1;
                break;
            }
        }
        if(breakPoint == -1){
            reverse(arr.begin(), arr.end());
            return;
        }
        cout<<breakPoint<<endl;
        // element just bigger than breakPoint
        for(int i=n-1; i>breakPoint; i--){
            if(arr[i]>arr[breakPoint]){
                swap(arr[i], arr[breakPoint]);
                break;
            }
        }
        reverse(arr.begin()+breakPoint+1, arr.begin()+n);        
    }
};