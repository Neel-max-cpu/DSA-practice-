class Solution {
public:
    int rec(int row, int col, vector<vector<int>>&arr){
        if(row==arr.size()-1) return arr[row][col];

        int up = arr[row][col] + rec(row+1, col, arr);
        int down = arr[row][col] + rec(row+1, col+1, arr);

        return min(up, down);
    }
    
    int memo(int row, int col, vector<vector<int>>&arr, vector<vector<int>>&dp){
        if(row==arr.size()-1) return arr[row][col];

        if(dp[row][col]!=-1) return dp[row][col];
        int up = arr[row][col] + memo(row+1, col, arr, dp);
        int down = arr[row][col] + memo(row+1, col+1, arr, dp);

        return dp[row][col] = min(up, down);
    }

    int tab(vector<vector<int>>&arr, int m){
        vector<vector<int>>dp(m, vector<int>(m, 0));
        for(int i=0;i<arr[m-1].size(); i++){
            dp[m-1][i] = arr[m-1][i];
        }

        for(int i=m-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        // for(auto it:dp) {
        //     for(auto x:it)
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        return dp[0][0];
    }
    
    int so(vector<vector<int>>&arr, int m){
        vector<int>next(m, 0);
        for(int i=0;i<arr[m-1].size(); i++){
            next[i] = arr[m-1][i];
        }

        for(int i=m-2; i>=0; i--){
            vector<int>temp(m, 0);
            for(int j=i; j>=0; j--){
                temp[j] = arr[i][j] + min(next[j], next[j+1]);
            }
            next = temp;
        }
        return next[0];

       
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // recursion ---
        // return rec(0,0, triangle);

        // dp memoization--
        /*
        vector<vector<int>>dp(m, vector<int>(m, -1));
        return memo(0,0, triangle, dp);
        */

        // dp tabulation ---
        // return tab(triangle, m);

        // sp optimization
        return so(triangle, m);
    }
};