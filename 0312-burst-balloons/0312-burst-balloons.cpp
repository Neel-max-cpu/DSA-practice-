class Solution {
public:
    int rec(vector<int>&arr, int i, int j){
        if(i>j) return 0;
        int ans = 0;
        for(int ind=i; ind<=j; ind++){
            int coins = arr[i-1]*arr[ind]*arr[j+1] + rec(arr, i, ind-1) + rec(arr, ind+1, j);
            ans = max(ans, coins);
        }
        return ans;
    }
    
    int memo(vector<int>&arr, int i, int j, vector<vector<int>>&dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;
        for(int ind=i; ind<=j; ind++){
            int coins = arr[i-1]*arr[ind]*arr[j+1] + memo(arr, i, ind-1, dp) + memo(arr, ind+1, j, dp);
            ans = max(ans, coins);
        }
        return dp[i][j] = ans;
    }

    int tab(vector<int>&arr, int n){
        vector<vector<int>>dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                if(i>j) continue;
                else{
                    int ans = 0;
                    for(int ind=i; ind<=j; ind++){
                        int coins = arr[i-1]*arr[ind]*arr[j+1] + dp[i][ind-1] + dp[ind+1][j];
                        ans = max(ans, coins);
                    }
                    dp[i][j] = ans;
                }
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // inserting 1 in front and back for ease
        nums.push_back(1);
        nums.insert(nums.begin(), 1);


        // little bit different start from reverse ----
        /*
        0  1 2 3 4  5---index
        1 ,3,1,5,8, 1 --array
        i = 1, j=4
        lets say we have 8(is the last guy to be executed, index=4) 
        so coins = (i-1)1*8*1(4+1) + f(1,3)+f(5,4) = 8 + f(1,3)+0(i>j) = 8+f(1,3)

        now f(1,3) - lets say 3(is the last guy to be executed, index=1)
        so coins = (i-1)*3*(j+1) + f(1,0)+f(2,3) = 1*3*8 + 0(i>j) +f(2,3) = 24+f(2,3)

        now f(2,3) - lets say 5(is the last guy to be executed, index=3)
        so coins = (i-1)*5*(j+1) + f(2,2) + f(4,3) = 3*5*8 + f(2,2) + 0(i>j) = 120+f(2,2)

        now f(2,2) - one option 1(is the last guy to be exectued, index 2)
        so coins = (i-1)*1*(j+1) + f(2, 1) + f(3, 2) = 3*1*5 + 0(i>j) + 0(i>j) = 15

        so total 15 + 120 + 24 + 8 = 167 which is max(is done for all the ind from i to j)

        */

        // recursion ---
        // return rec(nums, 1, n);

        // dp memoization --
        /*
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return memo(nums, 1, n, dp);
        */

        // dp tabualtion --
        return tab(nums, n);
        
    }
};