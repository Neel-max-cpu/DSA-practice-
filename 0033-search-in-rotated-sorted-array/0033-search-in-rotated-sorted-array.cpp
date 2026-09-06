class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right=n-1;
        int ans = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid]==target){
                ans = mid;
                return ans;
            }
            else if(arr[mid]>arr[right]){
                // here right side sorted in smaller, and left side sorted in bigger                
                if(arr[mid]>target){
                    if(target<=arr[right]){
                        // need to find in smller half - right
                        left = mid+1;
                    }
                    else{
                        right = mid-1;
                    }
                }
                else{
                    if(target>=arr[left]){
                        // need to find in larger half - left                        
                        right = mid-1;
                    }
                    else{
                        left = mid+1;                        
                    }
                }                
            }
            else{                
                // here left side sorted in smaller, and right side sorted in bigger                
                if(arr[mid]>target){
                    if(target>=arr[left]){
                        // need to find in smller half - left
                        right = mid-1;
                    }
                    else{
                        left = mid+1;
                    }                    
                }
                else{
                    if(target<=arr[right]){
                        // need to find in larger half - right
                        left = mid+1;                        
                    }
                    else{
                        right = mid-1;
                    }                    
                }                
            }
        }
        return ans;
    }
};