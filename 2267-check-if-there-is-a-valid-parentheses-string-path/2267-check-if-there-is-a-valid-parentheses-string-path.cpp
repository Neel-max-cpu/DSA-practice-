class Solution {
public:
    bool helper(vector<vector<char>>&arr, int n, int m, int row, int col, int count){                
        if(row==n-1 && col==m-1){
            // cout<<"final count: "<<count<<endl;
            return count==0 ? true : false;
        }

        // cout<<"current: "<<row<<", "<<col<<" count: "<<count<<endl;

        // down or right        
        bool down = false;
        bool right = false;
        if(row+1<n){
            int val = count;
            if(arr[row+1][col]=='(') val++;
            else val--;
            down = helper(arr, n, m, row+1, col, val);
        }
        if(col+1<m){
            int val = count;
            if(arr[row][col+1]=='(') val++;
            else val--;
            right = helper(arr, n, m, row, col+1, val);
        }

        return down || right;
    }

    bool memo(vector<vector<char>>&arr, int n, int m, int row, int col, int count,
    vector<vector<vector<int>>>&dp){    

        // also count dp[row][col][count] here count cant be less than 0
        if(count<0) return false;
        if(dp[row][col][count] != -1) return dp[row][col][count];
        
        if(row==n-1 && col==m-1){
            // cout<<"final count: "<<count<<endl;
            return count==0 ? true : false;
        }
                

        // down or right        
        bool down = false;
        bool right = false;
        if(row+1<n){
            int val = count;
            if(arr[row+1][col]=='(') val++;
            else val--;
            down = memo(arr, n, m, row+1, col, val, dp);
        }
        if(col+1<m){
            int val = count;
            if(arr[row][col+1]=='(') val++;
            else val--;
            right = memo(arr, n, m, row, col+1, val, dp);
        }

        bool res = down || right;
        dp[row][col][count] = res == true? 1 : 0;
        return res;
    }

    bool tab(vector<vector<char>>&arr, int n, int m, int maxCount, vector<vector<vector<int>>>&dp){
        if(arr[0][0]==')') return false;

        // base case -- at n-1, m-1, count should be 0(true)
        dp[n-1][m-1][0] = 1;
        
        // Fill from bottom-right towards top-left
        for(int row=n-1; row>=0; row--){
            for (int col = m-1; col >= 0; col--) {
                // Destination already initialized
                if (row == n-1 && col == m-1)
                    continue;

                for (int count = 0; count < maxCount; count++) {
                    bool possible = false;
                    // Go DOWN 
                    // (arr[row+1][col] is already calculated since we are comming from back)
                    if (row + 1 < n) {
                        int val = count;

                        if (arr[row + 1][col] == '(')
                            val++;
                        else
                            val--;

                        if (val >= 0 && val < maxCount)
                            possible |= dp[row + 1][col][val];
                    }

                    // Go RIGHT 
                    // (arr[row][col + 1] is already calculated since we are comming from back)
                    if (col + 1 < m) {
                        int val = count;
                        if (arr[row][col + 1] == '(')
                            val++;
                        else
                            val--;

                        if (val >= 0 && val < maxCount)
                            possible |= dp[row][col + 1][val];
                    }

                    dp[row][col][count] = possible;
                }
            }
        }

        // We start with '(' so initial balance = 1
        return dp[0][0][1];
    }

    bool hasValidPath(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();


        // recursion ---
        /*
        if(arr[0][0]=='(')
            return helper(arr, n, m, 0,0,1);
        else return false;
        */

        int maxCount = n+m;         
        // if all are '(' then we keep on adding and at n-1, m-1 it would be m+n        

        // memoization ---
        /*
        // initallize with 3 states -1 (not visite), 1 (true), 0 false;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(maxCount,-1)));
        if(arr[0][0]=='('){            
            return memo(arr, n, m, 0,0,1,dp);
        }
        else return false;
        */

        // tabulation -- here only 2 states 0,1
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(maxCount,0)));
        return tab(arr,n, m, maxCount, dp);                
    }
};