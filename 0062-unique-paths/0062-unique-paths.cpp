class Solution {
public:
    bool valid(int m, int n, int i, int j){
        if(i==m || j==n) return false;
        return true;
    }
    bool valid2(int m, int n, int i, int j){
        if(i<0 || j<0) return false;
        return true;
    }
    int doPathCheck(int m, int n, int starti, int startj){
        if(starti==m-1 && startj==n-1){
            return 1;
        }        
        int count1 = 0, count2=0;
        if(valid(m,n, starti+1, startj)){            
            count1 = doPathCheck(m, n, starti+1, startj);
        }
        if(valid(m,n, starti, startj+1)){
            count2 = doPathCheck(m, n, starti, startj+1);
        }
        return count1+count2;
    }    
    int doPathCheck2(int m, int n, int starti, int startj, vector<vector<int>>&dp){
        if(starti==0 && startj==0){
            return 1;
        }           

        //step3
        if(dp[starti][startj]!=-1) return dp[starti][startj];

        int count1 = 0, count2=0;
        if(valid2(m,n, starti-1, startj)){            
            count1 = doPathCheck2(m, n, starti-1, startj, dp);
        }
        if(valid2(m,n, starti, startj-1)){
            count2 = doPathCheck2(m, n, starti, startj-1, dp);
        }
        //step2
        return dp[starti][startj] = count1+count2;
    }
    int uniquePaths(int m, int n) {
        // int count = doPathCheck(m, n, 0,0);

        //step 1
        /*
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));             
        int count = doPathCheck2(m, n, m-1, n-1, dp);
        return count;
        */

        /*
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                int one=0, two=0;
                if(i-1>=0) one = dp[i-1][j];
                if(j-1>=0) two = dp[i][j-1];
                dp[i][j]= one+two;
            }
        }
        return dp[m-1][n-1];
        */
        
        // best
        vector<int>dp(n,0);
        dp[0] = 1;
        for(int i=0; i<m; i++){            
            for(int j=1; j<n; j++){
                if(i==0 && j==0) continue;
                int one = 0, two = 0;
                if(i-1>=0) one = dp[j];
                if(j-1>=0) two = dp[j-1];
                dp[j] = one+two;
            }            
        }
        return dp[n-1];
    }
};