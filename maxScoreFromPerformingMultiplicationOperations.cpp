class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        //memory limit exceeded
        // int n = nums.size();
        // int m = multipliers.size();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // for(int i = m-1; i > -1; i--){
        //     for(int j = i; j > -1; j--){
        //         dp[i][j] = max(multipliers[i] * nums[j] + dp[i+1][j+1], multipliers[i]*nums[n-1-i+j] + dp[i+1][j]); // select either from left or right
        //     }
        // }
        // return dp[0][0];
        
        int n = nums.size();
        int m = multipliers.size();
        vector<int> dp(m+1, 0);
        for(int i = m-1; i > -1; i--){
            vector<int> next_row(m+1);
            for(int k = 0; k <=m; k++)
                next_row[k] = dp[k];
            for(int j = i; j > -1; j--){
                dp[j] = max(multipliers[i]*nums[j] + next_row[j+1], multipliers[i]*nums[n-1-i+j] + next_row[j]); //for computing present row dp[i], we need next row dp[i+1] ONLY. Therefore, we can have 1D Array only. We will fill the dp array from bottom to top, saving the next row in a temporary array, and then computing the present row using the saved temporary array.
            }
        }
        return dp[0];
    }
};
