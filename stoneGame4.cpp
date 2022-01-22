class Solution {
public:
    int dp[100001];
    bool helper(int n){
        if(n == 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        for(int i = 1; i * i <= n; i++){
            if(helper(n-i*i) == 0)
                return dp[n] = 1;
        }
        return dp[n] = 0;
    }
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof dp);
        helper(n);
        return dp[n];
    }
};
