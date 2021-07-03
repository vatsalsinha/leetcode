class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<int> dp1(piles.size()), dp2(piles.size());
        dp1[0] = max(piles[0], piles[piles.size()-1]);
        dp2[0] = min(piles[0], piles[piles.size()-1]);
        for(int i = 1; i < piles.size(); i++){
            dp1[i] = max(dp1[i]+piles[i], dp1[i-1]);
            dp2[i] = min(dp2[i]+piles[i], dp2[i-1]);
        }
        return dp1[piles.size()-1] > dp2[piles.size()-1];
    }
};
