class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxDiff = 0, diff = prices[0];
        for(int i = 0; i < prices.size(); i++){
            diff = min(diff, prices[i]);
            maxDiff = max(maxDiff, prices[i]-diff);
        }
        return maxDiff;
    }
};
