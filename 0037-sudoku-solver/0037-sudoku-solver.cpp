
//editorial -- https://www.youtube.com/watch?v=FWAIf_EVUKE&list=TLPQMjYwMTIwMjOi8dKCtf_ChQ&index=3

class Solution {
public:

bool isValid(vector<vector<char>>&board, int row, int col, char c){
    for(int i=0;  i<9; i++){
        
        //checking column(up to down)
        if(board[i][col] == c)
            return false;
        
        //checking row(left to right)
        if(board[row][i] == c)
            return false;
        
        //checking for the 3x3 box
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
            return false;
    }
    return true;
}
public:
bool solve(vector<vector<char>> &board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){

            //if i find that a particular cell is empty, then we try out every possible combination
            if(board[i][j] == '.'){

                //so we try out from 1 to 9
                for(char c = '1'; c<='9'; c++){
                    //now when can i place a element here: when it follows the 3rule: number shouldn't be on the entire row/column/box(3x3)
                    if(isValid(board,i,j,c)){
                        //if it is valid put then filled
                        board[i][j] = c;

                        //after putting the element we send true 
                        if(solve(board)==true)
                            return true;
                        //since it got false we need to remove it so we removed it 
                        else board[i][j] = '.';
                    }
                }

                //if we can't place any element from 1 to 9
                return false;
            }
        }
    }
    //ultimately if all the send as true we wil send true(basically we can't find an empty cell '.')
    //then we don't go inside the if condition above so we ultimately return true without changeing the matrix(but this time it is filled up)
    return true;
}

public:
void solveSudoku(vector<vector<char>>& board){
    solve(board);
}



};