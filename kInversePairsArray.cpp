class Solution {
public:
    const int mod = pow(10, 9) + 7;
    int kInversePairs(int n, int k) {
        // int dp[n+1][k+1];
        // memset(dp, 0, sizeof(dp));
        // for(int i = 1; i <= n; i++){
        //     for(int j = 0; j <= k; j++){
        //         if(j == 0)
        //             dp[i][j] = 1;
        //         else{
        //             for(int p = 0; p <= min(j, i-1); p++)
        //                  dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % 1000000007;
        //         }
        //     }
        // }
        // return dp[n][k];
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            dp[i][0] = 1;
            for(int j = 1; j <= k; ++j){
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
                if(j - i >= 0){
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod; 
                    //It must + mod, If you don't know why, you can check the case 1000, 1000
                }
            }
        }
        return dp[n][k];
    }
};
