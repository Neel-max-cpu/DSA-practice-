class Solution {
public:
    bool isValid(int newi, int newj){
        if(newi<0 || newj<0) return false;
        return true;
    }

    int recursion(int endi, int endj){
        if(endi==0 && endj==0) return 1;

        //valid places left, up
        int count1 = 0, count2=0;
        if(isValid(endi, endj-1)){
            count1 = recursion(endi, endj-1);
        }
        if(isValid(endi-1, endj)){
            count2 = recursion(endi-1, endj);
        }        
        return count1+count2;        
    }
    
    //recursion to memoization
    int memoization(int endi, int endj, vector<vector<int>>&dp){
        // 1: base case
        if(endi==0 && endj==0) return 1;

        //2 check in dp
        if(dp[endi][endj]!=-1) return dp[endi][endj];

        //valid places left, up
        int count1 = 0, count2=0;
        if(isValid(endi, endj-1)){
            count1 = memoization(endi, endj-1, dp);
        }
        if(isValid(endi-1, endj)){
            count2 = memoization(endi-1, endj, dp);
        }        

        // 3 put the value in dp and return;
        dp[endi][endj] = count1+count2;        
        return dp[endi][endj];
    }
    
    int memoization2(int endi, int endj, vector<vector<int>>&dp){
        // 1: base case
        if(endi==1 && endj==1) return 1;

        //2 check in dp
        if(dp[endi][endj]!=-1) return dp[endi][endj];

        //valid places left, up
        int count1 = 0, count2=0;        
        if(endj>1) count1 = memoization2(endi, endj-1, dp);                
        if(endi>1) count2 = memoization2(endi-1, endj, dp);        

        // 3 put the value in dp and return;
        dp[endi][endj] = count1+count2;        
        return dp[endi][endj];
    }

    int uniquePaths(int m, int n) {

        //recursion --
        /*
        int count = recursion(m-1,n-1);
        return count;        
        */

        //memoization --- since 2 variables - 2d matrix
        /*
        // vector<vector<int>>dp(m, vector<int>(n,-1));
        // int count = memoization(m-1, n-1, dp);
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));    
        //can do m+1,n+1 to avoid boundary checks -- (+1 is just taken for conviniance)
        int count = memoization2(m, n, dp);
        return count;        
        */

        //tabulation
        // 1: same db from memoization but with 0 or with -1(0 preferred cause we look back and -1 may hamper)
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));

        // 2: write the base case
        // 0th row and col are the extra case here to avoid out of bounds
        dp[1][1] = 1;
        // 3: write the condition after the base case from memoization
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(i==1 && j==1) continue;      //base case rest do
                // 4: conditions of the memoization -- if initiallized with 0 then generally skip cause 0
                dp[i][j] = 0;
                if(i>1) dp[i][j]+=dp[i-1][j];
                if(j>1) dp[i][j] +=dp[i][j-1];                
                // dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        // 5:return the last value
        return dp[m][n];        

    }
};