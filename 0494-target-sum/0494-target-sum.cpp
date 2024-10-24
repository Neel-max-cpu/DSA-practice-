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
    
    int memo(vector<int>&arr, int k, int sum, int n, int i, unordered_map<string,int>&dp){
        if(i<0){
            if(k==sum) return 1;
            else return 0;
        }
        string key = to_string(i)+","+to_string(sum);

        if(dp.find(key)!=dp.end()) return dp[key];

        int pos = 0, neg = 0;
        pos = memo(arr, k, sum+arr[i], n, i-1, dp);
        neg = memo(arr, k, sum-arr[i], n, i-1, dp);
    
        return dp[key] = pos+neg;
    }

    // --------------------------------------------------------------------
    int rec(int n, int d, vector<int>&arr, int i, int s2){
        if(i<0){
            return (s2==0)? 1:0;
        }
        
        int pick = 0;
        if(arr[i]<=s2)
            pick = rec(n, d, arr, i-1, s2-arr[i]);
        int notpick = rec(n, d, arr, i-1, s2);
        
        return (pick+notpick);
    }
   
    int memo(int n, int d, vector<int>&arr, int i, int s2, vector<vector<int>>&dp){
        if(i<0){
            return (s2==0)? 1:0;
        }
        
        if(dp[i][s2]!=-1) return dp[i][s2];
        
        int pick = 0;
        if(arr[i]<=s2)
            pick = memo(n, d, arr, i-1, s2-arr[i], dp);
        int notpick = memo(n, d, arr, i-1, s2, dp);
        
        return dp[i][s2] = (pick+notpick);
    }
    
    int tab(int n, int d, vector<int>&arr, int sum){
        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
        
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int s2 = 0; s2<=sum; s2++){
                int pick = 0;
                if(arr[i-1]<=s2)
                    pick = dp[i-1][s2-arr[i-1]];
                int notpick = dp[i-1][s2];
                
                dp[i][s2] = (pick+notpick);
            }
        }
        
        return dp[n][sum];
    }
    
    int so(int n, int d, vector<int>&arr, int sum){
        vector<int>prev(sum+1, 0);
        
        prev[0] = 1;
        
        for(int i=1; i<=n; i++){
            vector<int>curr(sum+1, 0);
            for(int s2 = 0; s2<=sum; s2++){
                int pick = 0;
                if(arr[i-1]<=s2)
                    pick = prev[s2-arr[i-1]];
                int notpick = prev[s2];
                
                curr[s2] = (pick+notpick);
            }
            prev = curr;
        }
        
        return prev[sum];
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int totalsum = 0;
        for(auto it:arr) totalsum+=it;
        
        /*
        explainatino --- 
        (given) s1-s2 = d -- (i) and s1>=s2 ---(ii)
        
        s1 = totalsum-s2 ----(iii)
        therefore, (i) and (iii)
        totalsum-s2-s2 = d
        , s2 = (totalsum-d)/2
        
        edge case 
        1) s2 can be fraction, so totalsum-d can't be odd
        2) and totalsum<d can be 
        */
        
        int s2 = totalsum - d;
        if(s2%2==1 || s2<0) return 0;
        s2/=2;
        
        // recursion --
        // return rec(n, d, arr, n-1, s2);
        
        // memoization ---
        // /*
        vector<vector<int>>dp(n, vector<int>(s2+1, -1));
        return memo(n, d, arr, n-1, s2, dp);
        // */
        
        // tabulation ---
        // return tab(n, d, arr, s2);
        
        // space optimization --
        // return so(n, d, arr, s2);
    }
    // -----------------------------------------------------------
  

    int findTargetSumWays(vector<int>& nums, int target) {
        // same question ----- dp18
        // https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference

        //recursion ---
        int n = nums.size();
        // return rec(nums, target, 0, n, n-1);

        // dp memoization --- m1
        /*
        unordered_map<string,int>dp;
        return memo(nums, target, 0, n, n-1, dp);
        */
        // dp memoization --- m2
        return countPartitions(n, target, nums);

        // dp tabulation ---
    }
};