class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum % 2 != 0)
            return false;
        int n = nums.size();
        int m = sum/2;
        bool dp[n+1][m+1];
        memset(dp, 0, sizeof dp);
        for(int i = 0; i < n+1; i++)
            dp[i][0] = true;
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < m+1; j++){
                dp[i][j] = dp[i-1][j]; // excluding current ele
                if(j >= nums[i-1]){
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][m];
    }
};
