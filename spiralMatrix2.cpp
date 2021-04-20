class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        int min_row = 0;
        int min_col = 0;
        int max_row = n-1;
        int max_col = n-1;
        int tot = n*n;
        int count = 1;
        while(count <= tot){
            //min row ----->>
            for(int i = min_row, j = min_col; j <= max_col && count <= tot; j++){
                res[i][j] = count++;
               
            }
            min_row++;
            //max_col |
            //        v 
            for(int i = min_row, j = max_col; i <= max_row && count <= tot; i++){
                res[i][j] = count++;
                
            }
            max_col--; 
            //max_col <-------
            for(int i = max_row, j = max_col; j >= min_col && count <= tot; j--){
                res[i][j] = count++;
              
            }
            max_row--;   
            //max_row ^
            //        |
            for(int i = max_row, j = min_col; i >= min_row && count <= tot; i--){
                res[i][j] = count++;
                
            }
            min_col++;
        }
        return res;
    }
};
