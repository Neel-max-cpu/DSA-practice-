class Solution {
public:
    bool isValid(vector<vector<int>>&arr, vector<vector<bool>>&visited, int row, int col,
    int n, int m){
        if(row<0 || row>=n || col<0 || col>=m) return false;
        if(arr[row][col]==1) return false;
        if(visited[row][col]) return false;
        return true;
    }

    void helper(vector<vector<int>>&arr, vector<vector<bool>>&visited, int row, int col,
    int n, int m, bool &closed){
        visited[row][col] = true;        

        // If any land cell touches the boundary,
        // the entire island is not closed.
        if (row == 0 || row == n - 1 ||
            col == 0 || col == m - 1) {
            closed = false;
        }

        // up, down, left right
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};

        for(int i=0; i<4; i++){
            int newRow = row+dy[i];
            int newCol = col+dx[i];
            if(isValid(arr, visited, newRow, newCol, n, m)){
                helper(arr, visited, newRow, newCol, n, m, closed);
            }
        }
    }    

    int closedIsland(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==0 && !visited[i][j]){    
                    bool closed = true;                
                    helper(arr, visited, i, j, n, m, closed);
                    if(closed) count++;
                }
            }
        }
        return count;
    }
};