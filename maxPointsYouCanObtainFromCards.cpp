class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> preSum(cardPoints.size()+1, 0);
        for(int i = 1; i <= cardPoints.size(); i++){
            preSum[i] = preSum[i-1] + cardPoints[i-1];
        }
        int mn = INT_MAX;
        for(int i = 1, j = cardPoints.size() - k; j < cardPoints.size()+1; i++, j++){
            mn = min(mn, preSum[j]-preSum[i-1]); // to get the max sum, minimize the sum of the sub array of size n-k
        }
        return preSum[cardPoints.size()] - mn;
    }
};
