class Solution {
public:
    int sol(vector<vector<int>>& dp, int n, int k, int t){
        if(n < 0 || t < 0)
            return 0;
        if(n == 0 && t == 0)
            return 1;
        if(dp[n][t] != -1)
            return dp[n][t];
        int totWays = 0;
        for(int i = 1; i <= k; i++){
            if(i <= t)
                totWays = (totWays + sol(dp, n-1, k, t-i)) % 1000000007;
        }
        dp[n][t] = totWays;
        return totWays;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return sol(dp, n, k, target);
    }
};
