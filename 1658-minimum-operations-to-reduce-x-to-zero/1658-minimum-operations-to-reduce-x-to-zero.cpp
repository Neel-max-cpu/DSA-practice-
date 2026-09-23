class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size();
        int totalSum = 0;
        for(auto it:arr) totalSum+=it;

        int toLeave = totalSum-x;
        if(toLeave<0) return -1;
        if(toLeave == 0) return n;
        // find the longest subarray with sum toLeave
        int i = 0, j = 0;
        int maxLen = 0;
        int currSum = 0;
        while(j<n){
            currSum+=arr[j];                        
            while(currSum>toLeave){
                currSum-=arr[i++];
            }
            if(currSum==toLeave){
                int len = j-i+1;
                maxLen = max(maxLen, len);
            }
                        
            j++;
        }
        return maxLen == 0 ? -1 : n-maxLen; 
    }   
};