class Solution {
public:
    int rec(vector<int>&arr, int n, int i, vector<int>&v){
        if(i==n){
            return v.size();
        }
        
        int pick = -1e9;
        if(v.empty()||v.back()<arr[i]){
            v.push_back(arr[i]);
            pick = rec(arr, n, i+1, v);
            v.pop_back();
        }
        int notpick = rec(arr, n, i+1,v);

        return max(pick, notpick);
    }

    int rec2(vector<int>&arr, int n, int i, int prev){
        if(i==n){
            return 0;
        }

        int pick = 0;
        // if(prev==-1) pick = 1+rec2(arr, n, i+1, i);
        // else if(prev!=-1 && arr[i]>arr[prev]) pick = 1+rec2(arr, n, i+1, i);
        if(prev!=-1 || arr[i]>arr[prev]) pick = 1+rec2(arr, n, i+1, i);

        int notpick = 0 + rec2(arr, n, i+1, prev);
        return max(pick, notpick);
    }
    
    int memo(vector<int>&arr, int n, int i, int prev, vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int pick = 0;
        if(prev==-1 || arr[i]>arr[prev]) pick = 1+memo(arr, n, i+1, i, dp);        

        int notpick = 0 + memo(arr, n, i+1, prev, dp);
        return dp[i][prev+1] = max(pick, notpick);
    }

    int bm(vector<int>&arr, int n){
        vector<int>v;
        v.push_back(arr[0]);
        for(int i=1; i<n; i++){
            if(arr[i]>v.back()) v.push_back(arr[i]);
            else{                
                // binary search
                auto it = lower_bound(v.begin(), v.end(), arr[i]);
                *it = arr[i];
            }
        }
        return v.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans= -1e9;
        // recursion ---
        /*
        vector<int>v;
        return rec(nums, n, 0, v);
        */

        // recursion 2 ---
        // return rec2(nums, n, 0, -1);
        
        // dp memoization --
        /*
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return memo(nums, n, 0, -1, dp);
        */

        // best method ---
        return bm(nums, n);
    }
};