class Solution {
public:
    double optimal(vector<int>&arr1, vector<int>&arr2, int len){
        int n = arr1.size();
        int m = arr2.size();
        int left = 0;
        int right = n;

        while(left<=right){
            int midInArr1 = left+(right-left)/2;

            int totalInLeft = (len+1)/2;
            int midInArr2 = totalInLeft - midInArr1;

            int leftArr1 = INT_MIN, leftArr2 = INT_MIN;
            int rightArr1 = INT_MAX, rightArr2 = INT_MAX;

            int indexArr1 = midInArr1-1;
            int indexArr2 = midInArr2-1;

            if(indexArr1>=0) leftArr1 = arr1[indexArr1];
            if(indexArr2>=0) leftArr2 = arr2[indexArr2];
            if(indexArr1+1<n) rightArr1 = arr1[indexArr1+1];
            if(indexArr2+1<m) rightArr2 = arr2[indexArr2+1];

            if(leftArr1<=rightArr2 && leftArr2<=rightArr1){
                double ans;
                if(len%2==1){
                    ans = max(leftArr1, leftArr2);
                }
                else{
                    ans = (max(leftArr1, leftArr2)+min(rightArr1, rightArr2))/2.0;
                }
                return ans;
            }
            else if(leftArr1>rightArr2) right = midInArr1-1;
            else if(leftArr2>rightArr1) left = midInArr1+1;
        }
        return 0.0;
    }

    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        // take smaller one
        if(n>m) return findMedianSortedArrays(arr2, arr1);
        return optimal(arr1, arr2, n+m);
    }
};