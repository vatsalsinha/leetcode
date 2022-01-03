class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int dp[nums.size()][nums.size()];
        for(int g = 0; g < nums.size(); g++){
            for(int i = 0, j = g; j < nums.size(); i++, j++){
                int m = INT_MIN;
                for(int k = i; k < j+1; k++){
                    int l = k == i ? 0 : dp[i][k-1];
                    int r = k == j ? 0 : dp[k+1][j];
                    int val = (i == 0 ? 1 : nums[i-1]) * nums[k]*(j==nums.size()-1 ? 1 : nums[j+1]);
                    int tot = l+val+r;
                    m = max(tot, m);
                }
                dp[i][j] = m;
            }
        }
        return dp[0][nums.size()-1];
	// watch pepcoding's video for this question
    }
};
