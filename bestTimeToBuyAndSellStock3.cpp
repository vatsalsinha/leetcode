class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int pMin[n];
        int sMax[n];
        int preProfit[n+1];
        int sufProfit[n+1];
        pMin[0] = prices[0];
        sMax[n-1] = prices[n-1];
        preProfit[0] = 0;
        sufProfit[n-1] = 0;
        for(int i = 1; i < n; i++){
            pMin[i] = min(pMin[i-1], prices[i]);
            preProfit[i] = max(preProfit[i-1], prices[i] - pMin[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
            sMax[i] = max(sMax[i+1], prices[i]);
            sufProfit[i] = max(sufProfit[i+1], sMax[i]-prices[i]);
        }
        int profit = sufProfit[0];
        for(int i = 1; i < n; i++){
            int tmp = preProfit[i-1] + sufProfit[i];
            profit = max(tmp, profit);
        }
        return profit;
    }
};
