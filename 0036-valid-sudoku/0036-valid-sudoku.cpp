class Solution {
public:

    bool isValidRow(vector<vector<char>>&v, int row){
        unordered_set<char>seen;
        for(int col = 0; col<9; col++){
            char current = v[row][col];
            if(current!='.'){
                if(seen.find(current)!=seen.end())
                    return false;
                seen.insert(current);
            }
        }
        return true;        
    }

    bool isValidCol(vector<vector<char>>&v, int col){
        unordered_set<char>seen;
        for(int row = 0; row<9; row++){
            char current = v[row][col];
            if(current!='.'){
                if(seen.find(current)!=seen.end())
                    return false;
                seen.insert(current);
            }
        }
        return true;        
    }

    bool isValidSubMatrix(vector<vector<char>>&v, int row, int col){
        int start_row = (row/3)*3;
        int start_col = (col/3)*3;
        unordered_set<char>seen;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                char current = v[start_row+i][start_col+j];
                if(current!='.'){
                    if(seen.find(current)!=seen.end())
                        return false;
                    seen.insert(current);
                }
            }
        }       
        return true;
    }

    bool helper(vector<vector<char>> & v, int row, int col){
        if(row==8 && col==9) return true;

        if(col==9){
            row++;
            col = 0;
        }


        if(v[row][col]=='.') return helper(v, row, col+1);

        bool f1 = isValidRow(v, row);
        bool f2 = isValidCol(v, col);
        bool f3 = isValidSubMatrix(v, row, col);
        
        if(f1 && f2 && f3)
            return helper(v, row, col+1);
        else return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // method 2 --- 
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool sub[9][9] = {false};

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;

                int index = board[i][j] -'0'-1;
                int area = (i/3)*3+(j/3);

                if(row[i][index]==true || col[j][index]==true || sub[area][index]==true) return false;

                row[i][index] = true;            
                col[j][index] = true;            
                sub[area][index] = true;            
            }
        }
        return true;


        //my method --
        // return helper(board, 0, 0);
    }
};