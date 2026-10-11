class Solution {
public:
    int sumOfSquares(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            if(n% (i+1) == 0){
                int val = arr[i]*arr[i];
                sum += val;
            }
        }
        return sum;
    }
};