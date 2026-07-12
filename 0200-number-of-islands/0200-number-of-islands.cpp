class Solution {
public:

    bool valid(int row, int col, int n, int m, vector<vector<char>>&grid, vector<vector<bool>>&visited){
        if(row<0 || row>=n || col<0 || col>=m) return false;
        if(grid[row][col]=='0') return false;
        if(visited[row][col]) return false;
        return true;
    }

    void dfs(int row, int col, int n, int m, vector<vector<char>>&grid, vector<vector<bool>>&visited){
        visited[row][col] = true;

        // i can do in any 4 direction
        // left, up, right, down
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        for(int i=0; i<4; i++){
            int newRow = row+dy[i];
            int newCol = col+dx[i];
            if(valid(newRow, newCol, n, m, grid, visited)){
                dfs(newRow, newCol, n, m, grid, visited);
            }
        }
    }
    
    void bfs(int row, int col, int n, int m, vector<vector<char>>&grid, vector<vector<bool>>&visited){

        queue<pair<int,int>>q;        
        q.push({row, col});
        visited[row][col] = true;

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};

        while(!q.empty()){
            auto currNode = q.front();
            q.pop();
            int currRow = currNode.first;
            int currCol = currNode.second;            

            for(int i=0; i<4; i++){
                int newRow = currRow+dy[i];
                int newCol = currCol+dx[i];
                if(valid(newRow, newCol, n, m, grid, visited)){
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
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
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){                    
                    // dfs or bfs
                    // dfs(i,j, n, m, grid, visited);
                    bfs(i,j, n, m, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
};