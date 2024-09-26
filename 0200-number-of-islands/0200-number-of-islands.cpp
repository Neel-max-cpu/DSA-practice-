class Solution {
public:    
    void dfs(vector<vector<bool>>&visited, vector<vector<char>>&grid, int i, int j){
        visited[i][j] = true;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int n = grid.size();
        int m = grid[0].size();
        for (int k = 0; k < 4; k++) {
            int nrow = i + dx[k];
            int ncol = j + dy[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
                dfs(visited, grid, nrow, ncol);            
            }
        }
    }

    void bfs(vector<vector<bool>>&visited, vector<vector<char>>&grid, int i, int j){
        visited[i][j] = true;
        queue<pair<int,int>>q;
        q.push({i, j});
        int n = grid.size();
        int m = grid[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // here 8 direction searching wont' work
            /*     
            for(int ki = -1 ; ki<=1; ki++){
                for(int kj= -1; kj<=1; kj++){
                    int nrow = row+ki;
                    int ncol = col+kj;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !visited[nrow][ncol] ){
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
                }
            }
            */
            for (int k = 0; k < 4; k++) {
                int nrow = row + dx[k];
                int ncol = col + dy[k];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    // bfs
                    // bfs(visited, grid, i, j);
                    // dfs
                    dfs(visited, grid, i, j);
                }
            }
        }
        return count;
    }
};