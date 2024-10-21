class Solution {
public:
    int rec(vector<int>&arr, int k, int sum, int n, int i){
        if(i<0){
            if(k==sum) return 1;
            else return 0;
        }

        int pos = 0, neg = 0;
        pos = rec(arr, k, sum+arr[i], n, i-1);
        neg = rec(arr, k, sum-arr[i], n, i-1);

        return pos+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        //recursion ---
        int n = nums.size();
        return rec(nums, target, 0, n, n-1);

        // dp memoization ---
    }
};