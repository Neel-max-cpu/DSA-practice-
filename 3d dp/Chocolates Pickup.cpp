
/*
You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of chocolates collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the chocolates.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
Example:

Input:
n = 4, m = 3
grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output:
24
Explanation:
Path of robot #1 and #2 are described in color green and blue respectively. Chocolates taken by Robot #1, (3 + 2 + 5 + 2) = 12. Chocolates taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of Chocolates: 12 + 12 = 24.
Expected Time Complexity: O(n * m * m)
Expected Space Complexity: O(n * m * m)

Constraint:
2 <= n, m < = 70
0 <= grid[i][j] <= 100


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int rec(int n, int m , vector<vector<int>>& arr, int i, int j1, int j2){
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e9;
        
        if(i==n-1) {
            if(j1!=j2)
                return arr[i][j1]+arr[i][j2];
            else return arr[i][j1];
        }
        
        
        int ans = 0;
        for(int j0=-1; j0<=1; j0++){
            for(int j=-1; j<=1; j++){
                int newi = i+1;
                int newj1 = j1+j0;
                
                int newj2 = j2+j;
                
                int sum = 0;
                if(j1!=j2)
                    sum = (arr[i][j1] + arr[i][j2]) + rec(n, m, arr, newi, newj1, newj2);
                else 
                    sum = arr[i][j1] + rec(n, m, arr, newi, newj1, newj2);
                ans = max(sum, ans);
                
            }
        }
        return ans;
        
    }
    
    int memo(int n, int m , vector<vector<int>>& arr, int i, int j1, int j2,  vector<vector<vector<int>>>&dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e9;
        
        if(i==n-1) {
            if(j1!=j2)
                return arr[i][j1]+arr[i][j2];
            else return arr[i][j1];
        }
        
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        
        int ans = 0;
        for(int j0=-1; j0<=1; j0++){
            for(int j=-1; j<=1; j++){
                int newi = i+1;
                int newj1 = j1+j0;
                
                int newj2 = j2+j;
                
                int sum = 0;
                if(j1!=j2)
                    sum = (arr[i][j1] + arr[i][j2]) + memo(n, m, arr, newi, newj1, newj2, dp);
                else 
                    sum = arr[i][j1] + memo(n, m, arr, newi, newj1, newj2, dp);
                ans = max(sum, ans);
                
            }
        }
        return dp[i][j1][j2] = ans;
    }
    
    int tab(int n, int m, vector<vector<int>>&arr){
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        
        // base case from memo/rec
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                int value = 0;
                if(j1==j2) value = arr[n-1][j1];
                else value = arr[n-1][j1]+arr[n-1][j2];
                dp[n-1][j1][j2] = value;
            }
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    // write the recursion now
                    int ans = 0;
                    for(int j0=-1; j0<=1; j0++){
                        for(int j=-1; j<=1; j++){
                            int newi = i+1;
                            int newj1 = j1+j0;
                            
                            int newj2 = j2+j;
                            
                            int sum = 0;
                            if(j1!=j2){
                                // sum = (arr[i][j1] + arr[i][j2]) + dp[newi][newj1][newj2];
                                sum = arr[i][j1] + arr[i][j2];
                            }
                            else {
                                // sum = arr[i][j1] + dp[newi][newj1][newj2];
                                sum = arr[i][j1];
                            }
                            
                            if(newj1>=0 && newj1<m && newj2>=0 && newj2<m)
                                sum +=  dp[newi][newj1][newj2];
                            else sum += -1e9;
                            ans = max(sum, ans);
                        }
                    }
                    dp[i][j1][j2] = ans;
                }
            }
        }
        // starts at row 0, and col 0 and m-1
        return dp[0][0][m-1];
    }
    
    int so(int n, int m, vector<vector<int>>&arr){
        vector<vector<int>>prev(m, vector<int>(m,0));
        
        // base case from memo/rec
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                int value = 0;
                if(j1==j2) value = arr[n-1][j1];
                else value = arr[n-1][j1]+arr[n-1][j2];
                prev[j1][j2] = value;
            }
        }
        
        for(int i=n-2; i>=0; i--){
            vector<vector<int>>curr(m, vector<int>(m,0));
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    // write the recursion now
                    int ans = 0;
                    for(int j0=-1; j0<=1; j0++){
                        for(int j=-1; j<=1; j++){
                            int newi = i+1;
                            int newj1 = j1+j0;
                            
                            int newj2 = j2+j;
                            
                            int sum = 0;
                            if(j1!=j2){
                                // sum = (arr[i][j1] + arr[i][j2]) + dp[newi][newj1][newj2];
                                sum = arr[i][j1] + arr[i][j2];
                            }
                            else {
                                // sum = arr[i][j1] + dp[newi][newj1][newj2];
                                sum = arr[i][j1];
                            }
                            
                            if(newj1>=0 && newj1<m && newj2>=0 && newj2<m)
                                sum +=  prev[newj1][newj2];
                            else sum += -1e9;
                            ans = max(sum, ans);
                        }
                    }
                    curr[j1][j2] = ans;
                }
            }
            prev = curr;
        }
        // starts at row 0, and col 0 and m-1
        return prev[0][m-1];
    }
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        // recursion --
        // return rec(n, m, grid, 0, 0, m-1);
        
        // dp memoization --
        /*
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return memo(n, m, grid, 0, 0, m-1, dp);
        */
        
        // dp tabulation 
        // return tab(n, m, grid);
        
        // space optimization --
        return so(n,m, grid);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends