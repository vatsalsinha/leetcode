class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> preSum(n+1);
        preSum[0] = 0;
        for(int i = 1; i < n+1; i++){
            preSum[i] = preSum[i-1] + gain[i-1];
        }
        return max(*max_element(preSum.begin(), preSum.end()), 0);
    }   
};
