class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        //better --
        /*
        vector<int>maxLeft(n);
        vector<int>maxRight(n);
        maxLeft[0] = arr[0];
        maxRight[n-1] = arr[n-1];        
        for(int i=1; i<n; i++){
            maxLeft[i] = max(maxLeft[i-1], arr[i]);            
        }        
        for(int i=n-2; i>=0; i--){
            maxRight[i] = max(maxRight[i+1], arr[i]);            
        }

        int ans = 0;
        for(int i=0; i<n; i++){            
            ans += min(maxLeft[i], maxRight[i]) - arr[i];
            
        }
        return ans;
        */

        //best --
        // intution we need the smaller one out of left max/right max
        int l = 0, r = n-1;
        int leftMax = 0, rightMax = 0;
        int total = 0;
        while(l<=r){
            // which is smaller out of arr[l], arr[r]
            // and move smaller
            if(arr[l]<=arr[r]){
                if(arr[l]<leftMax){
                    total += leftMax-arr[l];
                }
                else{
                    leftMax = max(leftMax, arr[l]);
                }
                l++;
            }
            else if(arr[l]>arr[r]){
                if(arr[r]<rightMax){
                    total += rightMax-arr[r];
                }
                else{
                    rightMax = max(rightMax, arr[r]);
                }
                r--;
            }
        }
        return total;
        
    }
};