class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                if(i == 0){
                    dp[i][j] = matrix[i][j];
                }
                else if(j == 0 && i > 0){
                    dp[i][j] = min(dp[i-1][j] + matrix[i][j], dp[i-1][j+1] + matrix[i][j]);
                }
                else if(j == matrix[0].size()-1 && i > 0){
                    dp[i][j] = min(dp[i-1][j] + matrix[i][j], dp[i-1][j-1] + matrix[i][j]);
                }
                else if(j > 0 && j < matrix[0].size()-1 && i > 0){
                    dp[i][j] = min(dp[i-1][j+1] + matrix[i][j], min(dp[i-1][j-1] + matrix[i][j], dp[i-1][j] + matrix[i][j]));
                }
            }
        }
        return *min_element(dp[dp.size()-1].begin(), dp[dp.size()-1].end());
    }
};
