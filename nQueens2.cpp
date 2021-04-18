class Solution {
public:
    int count = 0;
    bool isPlacable(vector<string> &curr, int r, int c){
        for(int i = 0; i < c; i++){
            if(curr[r][i] == 'Q')
                return false;
        }
        for(int i = r, j = c; i>=0 && j >= 0; i--, j--){
            if(curr[i][j] == 'Q')
                return false;
        }
        for(int i = r, j = c; i<curr.size() && j>=0; i++, j--){
            if(curr[i][j] == 'Q')
                return false;
        }
        
        return true;
    }
    void backTrack(int n, int col, vector<string> &curr){
        if(col == n){
            count++;
            return;
            
        }
        for(int i = 0; i < n; i++){
            if(isPlacable(curr, i, col)){
                curr[i][col] = 'Q';
                backTrack(n, col+1, curr);
                curr[i][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        string s(n, '.');
        // for(int i = 0; i < n; i++){
        //     s += '.';
        // }
        vector<string> curr(n, s);
        backTrack(n, 0, curr);
        return count;
    }
};