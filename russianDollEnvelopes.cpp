class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>& a, vector<int>&b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; // sorts first on the basis of w and then h
        });
        vector<int> dp;
        for(int i = 0; i < envelopes.size(); i++){
            int index = lower_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
            if(index == dp.size())
                dp.push_back(envelopes[i][1]);
            else
                dp[index] = envelopes[i][1];
        }
        return dp.size();
    }
};

