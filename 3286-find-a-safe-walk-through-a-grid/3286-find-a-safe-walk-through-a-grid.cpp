class Solution {
public:
    bool isValid(int row, int col, int n, int m, vector<vector<bool>>&visited){
        if(row<0 || row>=n || col<0 || col>=m || visited[row][col]==true) return false;                
        else return true;
    }

    bool helper(vector<vector<int>>&v, int h, int row, int col, int n, int m, vector<vector<bool>>&visited){
        if(h<=0 || visited[row][col]) return false;
        if(row==n-1 && col==m-1) {
            if(h>0) 
                return true;
            else return false;
        }

        visited[row][col] = true;

        int dx[4]={-1, 1, 0, 0};
        int dy[4]={0, 0, -1, 1};

        for(int i=0; i<4; i++){
            int n_row = row+dx[i];
            int n_col = col+dy[i];
            if(isValid(n_row, n_col, n, m, visited)){
                if(helper(v, h-v[n_row][n_col], n_row, n_col, n, m, visited)) return true;
            }
        }
        visited[row][col] = false;
        return false;
    }

    bool isValid2(int row, int col, int n, int m) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    }


    bool helper2(vector<vector<int>>& v, int h, int row, int col, int n, int m, vector<vector<int>>& dp) {        
        if (h <= 0) return false;
        if (row == n - 1 && col == m - 1) return h > 0; 
        
        if (dp[row][col] >= h) return false;

        dp[row][col] = h; 

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int n_row = row + dx[i];
            int n_col = col + dy[i];
            if (isValid2(n_row, n_col, n, m)) {
                if (helper2(v, h - v[n_row][n_col], n_row, n_col, n, m, dp)) return true;
            }
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // return helper(grid, health-grid[0][0],0,0, n, m, visited);
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper2(grid, health-grid[0][0], 0, 0, n, m, dp);
    }
};