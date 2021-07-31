class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> TravelDay(days.begin(), days.end());
        vector<int> dp(366);
        for(int i = 1; i < 366; i++){
            dp[i] = dp[i-1];
            if(TravelDay.find(i) != TravelDay.end()){
                dp[i] = min({ dp[i - 1] + costs[0],   // 1st case
                             dp[max(0, i - 7)] + costs[1],  // 2nd case
                             dp[max(0, i - 30)] + costs[2]});  // 3rd case
            }
            }
        return dp[365];
    }
};
