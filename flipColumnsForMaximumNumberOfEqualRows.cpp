class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        //find the i-th row, which has the most number of row or have totally different rows in matrix which eventually gives ans;
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            vector<int> flip(n);
            for(int j = 0; j < n; j++)
                flip[j] = 1 - matrix[i][j]; 
            int count = 0;
            for(int k = i; k < m; k++){
                if(matrix[i] == matrix[k] || matrix[k] == flip)
                    count++;
            }
            ans = max(count, ans);
        }
        return ans;
    }
};
