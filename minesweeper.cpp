class Solution {
public:
    bool isOkay(vector<vector<char>>& board, int x, int y){
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
    void reveal(vector<vector<char>>& board, int x, int y){
        if(!isOkay(board, x, y))
            return;
        if(board[x][y] == 'E'){
            int count = 0;
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    if(i == 0 && j == 0)
                        continue;
                    else
                        if(isOkay(board, x+i, y+j) && board[x+i][y+j] == 'M')
                            count++;
                }
            }
            if(count > 0)
                board[x][y] = '0' + count;
            else{
                board[x][y] = 'B';
                for(int i = -1; i < 2; i++){
                    for(int j = -1; j < 2; j++){
                        if(i == 0 && j == 0)
                            continue;
                        else
                            reveal(board, x+i, y+j);
                    }
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
                return board;
        }
        reveal(board, click[0], click[1]);
        return board;
    }
};
