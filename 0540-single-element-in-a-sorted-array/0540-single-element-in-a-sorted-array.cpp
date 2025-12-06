class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        // pair starts with even/odd index 
        // after single element it become odd/even index

        // if mid is even then check for mid+1
        // if mid is odd then check for mid-1
        // if condition breaks check in the left half else go right

        int n = arr.size();
        if(n==1) return arr[0];
        
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid==0 && arr[mid]!=arr[mid+1]) return arr[mid];
            else if(mid==n-1 && arr[mid]!=arr[mid-1]) return arr[mid];
            else if(mid>0 && mid<n-1 && arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return arr[mid];
            else if(arr[mid]==arr[mid^1]) {         //correct pair
                // if mid is even then arr[mid]==arr[mid+1]
                // if mid is odd then arr[mid]==arr[mid-1]
                low = mid+1;
            }
            else if(arr[mid]!=arr[mid^1]) high = mid-1;
        }
        return -1;
    }
};