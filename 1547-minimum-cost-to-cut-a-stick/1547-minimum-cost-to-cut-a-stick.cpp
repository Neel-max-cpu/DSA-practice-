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

    int tab(vector<int>&arr, int c){
        // n+2 for safety
        vector<vector<int>>dp(c+2, vector<int>(c+2, 0));
        
        for(int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                // base case -- don't need initiallised with 0 
                // if(i>j) dp[i][j] = 0;
                if(i>j) continue;
                // else{
                    int ans = 1e9;
                    for(int k=i; k<=j; k++){             
                        int size = (arr[j+1] - arr[i-1]) + dp[i][k-1] + dp[k+1][j];
                        ans = min(size, ans);
                    }
                    dp[i][j] = ans;
                // }
            }
        }
        return dp[1][c];
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        
        
        /*
        int size = cuts.size();
        // important sort it---
        vector<int>v;
        v.push_back(0);
        for(int i=0; i<size; i++){
            v.push_back(cuts[i]);
        }
        v.push_back(n);
        int len = v.size();
        // start from 1 and len-2 , since that's the size of the cuts arry 0 and n are added to the front
        // and the end buy us
        */

        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);

        // recursion ---
        // return rec(v, 1, len-2);
        // return rec(cuts, 1, c);

        // dp memoization --
        /*
        // vector<vector<int>>dp(len, vector<int>(len, -1));
        // return memo(v, 1, len-2, dp);
        vector<vector<int>>dp(c+1, vector<int>(c+1, -1));
        return memo(cuts, 1, c, dp);
        */

        // dp tabulation ---
        return tab(cuts, c);
    }
};