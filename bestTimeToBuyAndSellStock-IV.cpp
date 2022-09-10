class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k >= prices.size()/2){
            int maxPro = 0;
            for(int i = 1; i < prices.size(); i++){
                if(prices[i] > prices[i-1])
                    maxPro += prices[i]-prices[i-1];
            }
            return maxPro;
        }
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        for(int i = 1; i < k+1; i++){
            int lMax = dp[i-1][0] - prices[0];
            for(int j = 1; j < prices.size(); j++){
                dp[i][j] = max(dp[i][j-1], prices[j] + lMax);
                lMax = max(dp[i-1][j]-prices[j], lMax);
            }
        }
        return dp[k][prices.size()-1];
    }
};
/*
dp[i, j] represents the max profit up until prices[j] using at most i transactions. 
dp[i, j] = max(dp[i, j-1], prices[j] - prices[jj] + dp[i-1, jj]) { jj in range of [0, j-1] }          = max(dp[i, j-1], prices[j] + max(dp[i-1, jj] - prices[jj]))
dp[0, j] = 0; 0 transactions makes 0 profit
dp[i, 0] = 0; if there is only one price data point you can't make any transaction.
we can either do not use the prices[j] (thus, dp[i][j-1]), or use prices[j] (if prices[j] is used, the last transaction must start some point, jj; then, before jj, we can do at most i - 1 transactions)

 */
