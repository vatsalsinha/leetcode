class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int dp[matrix.size()+1][matrix[0].size()+1];
        memset(dp,0,sizeof(dp));
        int res = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1')
                    dp[i+1][j+1] = min(dp[i][j+1], min(dp[i+1][j], dp[i][j])) + 1;
                res = max(res, dp[i+1][j+1]);
            }
        }
        return res*res;
    }
};
