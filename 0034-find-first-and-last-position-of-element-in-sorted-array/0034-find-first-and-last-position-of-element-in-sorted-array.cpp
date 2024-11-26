class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int pos = -1;
        int n = arr.size();          
        int left = 0, right = n-1;
        // finding the first occurance -- mid-1
        // finding the last occurance -- mid+1
        while(left<=right){
            int mid = (left+right)/2;
            if(arr[mid]==target){                                
                pos = mid;            
                right = mid-1;
            }
            if (arr[mid]<target){                
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        if(pos == -1){
            return {-1,-1};
        }

        // or then find the last pos
        int lpos = -1;
        left = 0, right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(arr[mid]==target){
                lpos = mid;
                left = mid+1;
            }
            else if(arr[mid]<target) left = mid+1;
            else right= mid-1;
        }
        return {pos,lpos};
        
        /*
        int epos = pos;
        for(int i=pos+1; i<n; i++){
            if(arr[pos]!=arr[i]){
                epos = i-1;
                break;
            }
            epos = i;
        }
        return {pos, epos};
        */
    }
};