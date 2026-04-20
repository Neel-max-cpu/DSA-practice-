class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>&arr, vector<vector<bool>>&visited, string &word, int idx){
        if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size()) return false;
        if(visited[i][j]) return false;
        if(arr[i][j]!=word[idx]) return false;

        return true;
    }

    bool helper(vector<vector<char>>&arr, int startI, string &word, int startR, int startC, string &s, 
        vector<vector<bool>>&visited){

        visited[startR][startC] = true;
        s.push_back(word[startI]);

        if(s==word) return true;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int i=0; i<4; i++){
            int newI = startR+dy[i];
            int newJ = startC+dx[i];
            if(isValid(newI, newJ, arr, visited, word, startI+1)){
                if(helper(arr, startI+1, word, newI, newJ, s, visited)) return true;
            }
        }

        s.pop_back();
        visited[startR][startC] = false;
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx) {
        if(idx == word.size()) return true;

        if(
            i < 0 
            || j < 0 
            || i >= board.size() 
            || j >= board[0].size() 
            || board[i][j] != word[idx]
        ) return false;

        char temp = board[i][j];
        // saving visted arr space ---
        board[i][j] = '#';

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int k = 0; k < 4; k++) {
            if(dfs(board, i + dx[k], j + dy[k], word, idx + 1)) 
                return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& arr, string word) {
        int n = arr.size();
        int m = arr[0].size();
        // brute --
        /*
        vector<vector<bool>>visited(n, vector<bool>(m, false));

        string s = "";
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==word[0]){
                    if(helper(arr, 0, word, i, j, s, visited)) return true;
                }
            }
        }
        return false;
        */

        // optimal -----        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(arr, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};