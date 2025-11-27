class Solution {
public:

    bool isvalid(int row, int col, int n, vector<string>&board){
        // when directly above is not queen
        // when that point(row, col) to left diagonal up no queen
        // when that point(row, col) to right diagonal up no queen

        // check directly up--
        for(int i=row-1; i>=0; i--){
            // if(visited[i][col]==1){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        // left diagonal up
        int i = row-1, j=col-1;
        while(i>=0 && j>=0){
            // if(visited[i][j]==1) return false;
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }

        // right diagonal up
        i = row-1, j=col+1;
        while(i>=0 && j<n){
            // if(visited[i][j]==1) return false;
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }

        // if all condition satisfy
        return true;
    }
    // void helper(int n, int row, vector<vector<string>>&ans, vector<vector<bool>>&visited){
    void helper(int n, int row, vector<vector<string>>&ans, vector<string>&board){
        // base case
        if(row == n){
            ans.push_back(board);
            /*
            vector<string>temp;
            for(int i=0; i<n; i++){
                string s = "";
                for(int j=0; j<n; j++){
                    if(visited[i][j]==1){
                        // ''->char ""->string                    
                        s+="Q";
                    }
                    else{                        
                        s+=".";
                    }
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            */
            return;
        }
        
        for(int j=0;j<n; j++){
            // if(isvalid(row, j, n, visited)){
            if(isvalid(row, j, n, board)){
                // visited[row][j] = 1;
                board[row][j] = 'Q';
                // helper(n, row+1, ans, visited);
                helper(n, row+1, ans, board);
                // visited[row][j] = 0;
                board[row][j] = '.';
            }        
        }
    }

   

    bool isvalid2(int row, int col, int n, vector<string>&board){
        // when directly left is not queen
        // when that point(row, col) to left down diagonal no queen
        // when that point(row, col) to right up diagonal no queen

        // check directly left--
        for(int j=col-1; j>=0; j--){
            // if(visited[row][j]==1){
            if(board[row][j]=='Q'){
                return false;
            }
        }

        // left down diagonal
        int i = row+1, j=col-1;
        while(i<n && j>=0){
            // if(visited[i][j]==1) return false;
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }

        // right up diagonal
        i = row-1, j=col-1;
        while(i>=0 && j>=0){
            // if(visited[i][j]==1) return false;
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }

        // if all condition satisfy
        return true;
    }
    // void helper2(int n, int col, vector<vector<string>>&ans, vector<vector<bool>>&visited){
    void helper2(int n, int col, vector<vector<string>>&ans, vector<string>&board){
        // base case
        if(col == n){
            ans.push_back(board);
            /*
            vector<string>temp;
            for(int i=0; i<n; i++){
                string s = "";
                for(int j=0; j<n; j++){
                    if(visited[i][j]==1){
                        // ''->char ""->string                    
                        s+="Q";
                    }
                    else{                        
                        s+=".";
                    }
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            */
            return;
        }
        
        for(int i=0;i<n; i++){
            // if(isvalid2(i, col, n, visited)){
            if(isvalid2(i, col, n, board)){
                // visited[i][col] = 1;
                board[i][col] = 'Q';
                // helper2(n, col+1, ans, visited);
                helper2(n, col+1, ans, board);
                // visited[i][col] = 0;
                board[i][col] = '.';
            }        
        }
    } 

     void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        // check if we can place -- leftrow(directly left)
        // lower diagonal(row+col)
        // upper diagonal(n-1 + col-row)
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          
        // update the hash
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;

        // recursive call
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);

        // backtrack
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        // my way ---
        // /*
        vector<vector<string>>ans;
        // vector<vector<bool>>visited(n, vector<bool>(n,0));
        vector<string>board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        
        // check row wise ---- do row wise more natural --
        // helper(n, 0, ans, visited);
        helper(n, 0, ans, board);
        
        // check column wise ---
        // helper2(n, 0, ans, visited);
        // helper2(n, 0, ans, board);
        
        return ans;
        // */

        // optimised ---- where is valid function is omitted and see vector<string>boards(how it is used as a 2d vector!!!)
        // done col wise ---
        // vector < vector < string >> ans;
        // vector < string > board(n);
        // string s(n, '.');
        // for (int i = 0; i < n; i++) {
        //     board[i] = s;
        // }
        // // left -- direct check for the left
        // // upperDiagonal is upper left diagonal [n-1 + (col-row)]
        // // lowerDiagonal is left lower diagonal [row+col]
        // // three ways --
        // /*
        //     <-
        //       -
        //        - 
        //         -
        //     <----
        //         -
        //        -
        //       -
        //     <-        
        // */
        // vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        // solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
        // return ans;
    }
};