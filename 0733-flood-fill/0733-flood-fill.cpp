class Solution {
public:
    bool check(int newi, int newj, vector<vector<int>>&arr, int original, vector<vector<bool>>&visited){
        int n = arr.size();
        int m = arr[0].size();
        if(newi >= n || newi<0 || newj >=m || newj<0) return false;
        if(visited[newi][newj]) return false;
        if(arr[newi][newj]!=original) return false;
        return true;
    }

    void helper(vector<vector<int>>&arr, int row, int col, int color, vector<vector<bool>>&visited, int original, vector<vector<int>>&ans){
        visited[row][col] = true;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for(int i=0; i<4; i++){
            int newi = row+dy[i];
            int newj = col+dx[i];            
            ans[row][col] = color;
            if(check(newi, newj, arr, original, visited)){
                helper(arr, newi, newj, color, visited, original, ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        vector<vector<int>>ans = image;
        int original = image[sr][sc];
        helper(image, sr, sc, color, visited, original, ans);      
        return ans;
    }
};