class Solution {
public:
    void helper(vector<vector<int>>& arr, vector<vector<bool>>&visited, int row, int col, int n, int m,
    long long &sum){
        visited[row][col] = true;
        sum = sum + (long long)arr[row][col];

        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        for(int i=0; i<4; i++){
            int newRow = dy[i]+row;
            int newCol = dx[i]+col;
            if(newRow>=0 && newRow<n && 
            newCol>=0 && newCol<m && 
            arr[newRow][newCol]>0 && !visited[newRow][newCol]){
                helper(arr, visited, newRow, newCol, n, m, sum);
            }
        }
    }


     long long dfs(vector<vector<int>>& arr, int row, int col, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || arr[row][col] <= 0)
            return 0;

        long long sum = arr[row][col];

        // Mark visited by changing the cell to 0
        arr[row][col] = 0;

        sum += dfs(arr, row - 1, col, n, m);
        sum += dfs(arr, row + 1, col, n, m);
        sum += dfs(arr, row, col - 1, n, m);
        sum += dfs(arr, row, col + 1, n, m);

        return sum;
    }


    int countIslands(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int m = arr[0].size();

        vector<vector<bool>>visited(n, vector<bool>(m, false));

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                // mine --
                /*
                if(arr[i][j]>0 && !visited[i][j]){
                    long long sum = 0;                    
                    helper(arr, visited, i, j, n, m, sum);
                    if(sum%k==0) count++;
                }
                */

                // optimal ---
                if (arr[i][j] > 0) {
                    long long sum = dfs(arr, i, j, n, m);
                    if (sum % k == 0) count++;
                }
            }
        }
        return count;
    }
};