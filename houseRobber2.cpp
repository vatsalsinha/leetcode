class Solution {
public:
    int helper(vector<int> nums, int start, int end){
        int dp[end-start+1];
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        for(int i = start+2; i < end+1; i++){
            dp[i-start] = max(nums[i] + dp[i-start-2], dp[i-start-1]);
        }
        return dp[end-start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            if(n == 1)
                return nums[0];
            else
                return max(nums[0], nums[1]);
        }
        return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }
};
