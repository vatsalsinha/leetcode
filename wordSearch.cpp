class Solution {
public:
   bool search(vector<vector<char>>& board, string& word, int pos, int i, int j, int r, int c, vector<vector<bool>> &visited){
        if(i >= r || j >= c || i < 0 || j < 0 || word[pos] != board[i][j] || visited[i][j])
            return false;
    
        if(pos == word.length()-1)
            return true;
        
        //board[i][j] = '#'; // to avoid using of this character again in the backtracking
        visited[i][j] = true; 
       if(search(board, word, pos+1, i+1, j, r, c, visited) || search(board, word, pos+1, i-1, j, r, c, visited) || search(board, word, pos+1, i, j+1, r, c, visited) || search(board, word, pos+1, i, j-1, r, c, visited))
            return true;
	
        //board[i][j] = word[pos]; // Reassigning the character as backtracking is complete.
        visited[i][j] = false; 
       return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size()));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(search(board,word,0,i,j,board.size(), board[0].size(), visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
