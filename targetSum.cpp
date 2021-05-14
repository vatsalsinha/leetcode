class Solution {
public:
    int help(vector<int> nums, vector<unordered_map<int, int>> &dp, int currIndex, int currSum, int target){
        if(currIndex == nums.size()){
            return currSum == target ? 1 : 0;
        }
        if(!dp[currIndex].count(currSum)){
            int posi = help(nums, dp, currIndex+1, currSum+nums[currIndex], target);
            int negi = help(nums, dp, currIndex+1, currSum-nums[currIndex], target);
            dp[currIndex][currSum] = posi+negi;
        }
        return dp[currIndex][currSum];
    } 
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp(nums.size());
        return help(nums, dp, 0, 0, target);
    }
};
