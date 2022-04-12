class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dir = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                int countOnes = 0;
                for(int k = 0; k < 8; k++){
                    int I = dir[k][0] + i;
                    int J = dir[k][1] + j;
                    if(I < 0 || I >= board.size() || J < 0 || J >= board[0].size())
                        continue;
                    if(board[I][J] & 1)
                        countOnes++;
                }
                if(board[i][j] == 0) {
                    if(countOnes == 3){
                        board[i][j] = 2; // 2 : (10)
                    }
                }
                else {
                    if(countOnes < 2 || countOnes > 3){
                        board[i][j] = 1; // 1 : (01)
                    }else{
                        board[i][j] = 3; // 3 : (11)   
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                board[i][j] >>= 1; // in place
            }
        }
    }
};
