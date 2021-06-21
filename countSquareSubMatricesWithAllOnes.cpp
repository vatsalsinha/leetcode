class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        /*
       int dp[matrix.size()+1][matrix[0].size()+1];
        memset(dp,0,sizeof(dp));
        int res = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j]){
                    dp[i+1][j+1] = min(dp[i][j+1], min(dp[i+1][j], dp[i][j])) + 1;
                }
                res += dp[i+1][j+1];
            }
        }
        for(int i = 0; i <= matrix.size(); i++){
            for(int j = 0; j <= matrix[0].size(); j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return res;
        */
        int res = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] && i > 0 && j > 0){
                    matrix[i][j] = min(matrix[i-1][j], min(matrix[i][j-1], matrix[i-1][j-1])) + 1;
                }
                res += matrix[i][j];
            }
        }
        return res;
    }
};
