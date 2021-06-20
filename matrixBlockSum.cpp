class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        int dp[row+1][col+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i < row+1; i++){
            for(int j = 1; j < col + 1; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] + mat[i-1][j-1] - dp[i-1][j-1]; // subtracting the common term
            }
        }
        vector<vector<int>> ans(row, vector<int>(col));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int r1 = max(i-k,0);
                int c1 = max(j-k,0);
                int r2 = min(i+k, row-1);
                int c2 = min(j+k, col-1);
                r1++; r2++; c1++; c2++; // since dp is of size row+1*col+1
                ans[i][j] = dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1]; // watch tushar roy's video(12-14min)
            }
        }
        return ans;
    }
};
