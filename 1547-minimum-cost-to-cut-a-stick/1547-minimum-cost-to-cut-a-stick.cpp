class Solution {
public:
    int rec(vector<int>&arr, int i, int j){
        if(i>j) return 0;

        int ans = 1e9;
        for(int k=i; k<=j; k++){             
            int size = (arr[j+1] - arr[i-1]) + rec(arr, i, k-1) + rec(arr, k+1, j);
            ans = min(size, ans);
        }
        return ans;
    }
    
    int memo(vector<int>&arr, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 1e9;
        for(int k=i; k<=j; k++){             
            int size = (arr[j+1] - arr[i-1]) + memo(arr, i, k-1, dp) + memo(arr, k+1, j, dp);
            ans = min(size, ans);
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        // important sort it---
        sort(cuts.begin(), cuts.end());
        vector<int>v;
        v.push_back(0);
        for(int i=0; i<size; i++){
            v.push_back(cuts[i]);
        }
        v.push_back(n);
        int len = v.size();
        // start from 1 and len-2 , since that's the size of the cuts arry 0 and n are added to the front
        // and the end buy us

        // recursion ---
        // return rec(v, 1, len-2);

        // dp memoization --
        vector<vector<int>>dp(len, vector<int>(len, -1));
        return memo(v, 1, len-2, dp);
    }
};