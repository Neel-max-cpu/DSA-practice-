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
        return helper(board, 0, 0);
    }
};