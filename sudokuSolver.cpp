class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == c)
                return false;
        }
        for(int i = 0; i < 9; i++){
            if(board[row][i] == c)
                return false;
        }
        int boxR = (row/3) * 3; // grid
        int boxC = (col/3) * 3; //grid
        //check box
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[boxR + i][boxC + j] == c)
                    return false;
            }
        }
        return true;
    }
    
    void backtrack(vector<vector<char>>& board, vector<vector<char>> tmp, int row, int col){
        if(row == 9){
            board = tmp;
            return;
        }
        int next_row, next_col;
        if(col == 8){
            next_row = row + 1;
            next_col = 0;
        }
        else{
            next_row = row;
            next_col = col + 1;
        }
        if(tmp[row][col] != '.'){
            backtrack(board, tmp, next_row, next_col);
        }
        else{
            for(char c = '1'; c <= '9'; c++){
                if(isValid(tmp, row, col, c)){
                    tmp[row][col] = c;
                    backtrack(board, tmp, next_row, next_col);
                    tmp[row][col] = '.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> tmp = board;
        backtrack(board, tmp, 0, 0);            
    }
};