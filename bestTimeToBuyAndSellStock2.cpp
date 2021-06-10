class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for(int i = 0; i < prices.size()-1; i++){
            sum += prices[i+1] - prices[i] > 0 ? prices[i+1] - prices[i] : 0;
        }
        return sum;
    }
};
