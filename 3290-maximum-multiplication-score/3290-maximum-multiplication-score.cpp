class Solution {
public:
    int ans = INT_MIN;
    vector<vector<long long>> dp;
    void helper(vector<int>&a, vector<int>&b, int i, int j, int n, int sum){
        if(i==4 && j<=n) {
            ans = max(ans, sum);
            return;
        }
        if(i<4 && j==n){
            return;
        }

        helper(a, b, i+1, j+1, n, sum+(a[i]*b[j]));
        helper(a,b, i, j+1, n, sum);
    }

    long long helper2(vector<int>& a, vector<int>& b, int i, int j, int n) {
        if (i == 4) {            
            return 0;
        }
        if (j == n) {            
            return LLONG_MIN / 2; 
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        long long pick = (long long)a[i] * b[j] + helper2(a, b, i + 1, j + 1, n);
        
        long long skip = helper2(a, b, i, j + 1, n);
        
        return dp[i][j] = max(pick, skip);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        
        int i=0, j=0;
        int n = b.size();
        // helper(a, b, i, j, n, 0);
        // return ans;        
        dp = vector<vector<long long>>(4, vector<long long>(n, -1));
        return helper2(a, b, 0, 0, n);
    }
};