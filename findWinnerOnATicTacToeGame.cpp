class Solution {
public:
    bool check(vector<vector<char>> board, int row, int col, char player){
        bool didPlayerWin = true;
        for(int i = 0; i < 3; i++){
            if(board[row][i] != player){
                didPlayerWin = false;
            }                
        }
        if(didPlayerWin) return true;   //player has won the game
        
        //check the current col
        didPlayerWin = true;
        for(int i = 0; i < 3; i++){
            if(board[i][col] != player){
                didPlayerWin = false;
            }                
        }
        if(didPlayerWin) return true;   //player has won the game
        
        //check the diagonal
        if(row == col){
            didPlayerWin = true;
            for(int i = 0; i < 3; i++){
                if(board[i][i] != player){
                    didPlayerWin = false;
                }                
            }
            if(didPlayerWin) return true;   //player has won the game    
        }
        
        //check reverse diagonal
        if(col == 3 - row - 1){
            didPlayerWin = true;
            for(int i = 0; i < 3; i++){
                if(board[i][3-i-1] != player){
                    didPlayerWin = false;
                }                
            }
            if(didPlayerWin) return true;   //player has won the game    
        }
        
        //player did not win
        return false;
    }
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> box(3, vector<char>(3));
        for(int i = 0; i < moves.size(); i++){
            int row = moves[i][0];
            int col = moves[i][1];
            if((i & 1) == 0){
                box[row][col] = 'X';
                if(check(box, row, col, 'X'))
                    return "A";
            }
            else{
                box[row][col] = 'O';
                if(check(box, row, col, 'O'))
                    return "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
