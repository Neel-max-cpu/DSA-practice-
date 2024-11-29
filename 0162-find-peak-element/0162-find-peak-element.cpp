class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        // since arr[-1] is -infinity and we can return any peak(so no need to solve or others)
        if(arr[0]>arr[1]) return 0;
        // since arr[n] is -infinity and we can return any peak(so no need to solve or others)    
        if(arr[n-1]>arr[n-2]) return n-1;
        int left = 1, right = n-2;
        while(left<=right){
            int mid = (left+right)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;
            // increasing so peak would be in the right
            if(arr[mid-1]<arr[mid]) left = mid+1;
            // decreasing so peak would be in the left
            else right = mid-1;
        }
        return -1;
    }
};