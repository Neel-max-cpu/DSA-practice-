class Solution {
public:
    bool isValid(int r, int c, int n, int m, vector<vector<bool>>&visited, vector<vector<int>>&image, int current){
        if(r<0 || r==n || c<0 || c==m || visited[r][c]==true || image[r][c]!=current) return false;
        return true;
    }
    void helper(vector<vector<int>>&image, int sr, int sc, int color, vector<vector<bool>>&visited, int n, int m){
        
        visited[sr][sc] = true;
        int current = image[sr][sc];        
        int dx[]={-1, 1, 0, 0};
        int dy[]={0, 0, -1, 1};
        for(int i=0; i<4; i++){
            int nr = sr+dx[i];
            int nc = sc+dy[i];
            if(isValid(nr, nc, n, m, visited, image, current)){
                helper(image, nr, nc, color, visited, n, m);
            }
        }
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        vector<vector<int>>v(n, vector<int>(m));
        helper(image, sr, sc, color, visited, n, m);
        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j]==true)v[i][j]=color;
                else v[i][j]=image[i][j];
            }
        }
        return v;
    }
};