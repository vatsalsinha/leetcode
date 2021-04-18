class Solution {
public:
    vector<vector<string>> result;
    bool isPlacable(int r, int c, vector<string> &curr){
        //checking for rows 
        for(int i = 0; i < c; i++){
            if(curr[r][i] == 'Q'){
                return false;
            }
        }
        //checking for upper diagonal
        for(int i = r, j = c; i>=0 && j>=0; i--, j--){
            if(curr[i][j] == 'Q'){
                return false;
            }
        }
        //checking for lower diagonal
        for(int i = r, j = c; i < curr.size() && j>=0; i++, j--){
            if(curr[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void backtrack(int n, int col, vector<string> &curr){
        if(col == n){
            result.push_back(curr);
            return;
        }
        for(int i = 0; i < n; i++){
            if(isPlacable(i, col, curr)){
                curr[i][col] = 'Q';
                backtrack(n, col+1, curr);
                curr[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i = 0; i < n; i++){
            s += '.';
        }
        vector<string> curr(n,s);
        backtrack(n, 0, curr);
        return result;
    }
};
