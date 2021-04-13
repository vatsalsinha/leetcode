class Solution {
public:
    bool checkrow(vector<char> v){
        unordered_map<char, int> ump;
        for(char c: v){
            if(c != '.'){
                if(ump[c]){
                    return false;
                }
                ump[c]++;
            }
        }
        return true;
    }
    bool checkcol(vector<vector<char>> v, int n){
        unordered_map<char, int> ump;
        for(auto c: v){
            if(c[n] != '.'){
                if(ump[c[n]]){
                    return false;
                }
                ump[c[n]]++;
            }
        }
        return true;
    }
        
    bool checkbox(vector<vector<char>> v, int m, int n){
        unordered_map<char, int> ump;
        for(int i = m; i < m+3; i++){
            for(int j = n; j < n+3; j++){
                if(v[i][j] != '.'){
                    if(ump[v[i][j]]){
                        return false;
                    }
                    ump[v[i][j]]++;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            if(!checkrow(board[i]) || !checkcol(board, i)){
                return false;
            }
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                if(!checkbox(board, i, j)){
                    return false;
                }
            }
        }
        return true;
    }
};
