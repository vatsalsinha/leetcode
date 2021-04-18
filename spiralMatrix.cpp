class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int min_row = 0;
        int min_col = 0;
        int max_row = matrix.size()-1;
        int max_col = matrix[0].size()-1;
        int tot = matrix.size() * matrix[0].size();
        int count = 0;
        while(count < tot){
            //min row ----->>
            for(int i = min_row, j = min_col; j <= max_col && count < tot; j++){
                res.push_back(matrix[i][j]);
                count++;
            }
            min_row++;
            //max_col |
            //        v 
            for(int i = min_row, j = max_col; i <= max_row && count < tot; i++){
                res.push_back(matrix[i][j]);
                count++;
            }
            max_col--; 
            //max_col <-------
            for(int i = max_row, j = max_col; j >= min_col && count < tot; j--){
                res.push_back(matrix[i][j]);
                count++;
            }
            max_row--;   
            //max_row ^
            //        |
            for(int i = max_row, j = min_col; i >= min_row && count < tot; i--){
                res.push_back(matrix[i][j]);
                count++;
            }
            min_col++;
        }
        return res;
    }
};