class Solution {
public:
    int rec(string s1, string s2, int i, int j){
        
        if(i<0 && j>=0){
            return j+1;
        }    
        
        if(i>=0 && j<0){
            return i+1;
        }
        
        if(i<0 && j<0) return 0;

        // insert, delete, replace
        int one = 0;
        if(s1[i]==s2[j]) one = rec(s1, s2, i-1, j-1);
        else one = 1+rec(s1, s2, i-1, j-1);
        int two = 1, three=1;
        two += rec(s1, s2, i-1, j);
        three += rec(s1, s2, i, j-1);

        return min({one, two, three});

    }
    
    int memo(string s1, string s2, int i, int j, vector<vector<int>>&dp){
        
        if(i<0 && j>=0){
            return j+1;
        }    
        
        if(i>=0 && j<0){
            return i+1;
        }
        
        if(i<0 && j<0) return 0;


        if(dp[i][j]!=-1) return dp[i][j];

        // insert, delete, replace
        int one = 0;
        if(s1[i]==s2[j]) one = memo(s1, s2, i-1, j-1, dp);
        else one = 1+memo(s1, s2, i-1, j-1, dp);
        int two = 1, three=1;
        two += memo(s1, s2, i-1, j, dp);
        three += memo(s1, s2, i, j-1, dp);

        return dp[i][j] = min({one, two, three});

    }

    int minDistance(string word1, string word2) {
        // recrusion ---
        int n = word1.size();
        int m = word2.size();
        if(n==0 || m==0){
            return max(n, m);
        } 
        // return rec(word1, word2, n-1, m-1);

        // dp memoization ---
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return memo(word1, word2, n-1, m-1, dp);
    }
};