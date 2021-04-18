class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //karden's algorithm
        if(nums.size() == 1){
            return nums[0];
        }
       int smallest = *min_element(nums.begin(), nums.end());
        int current_max = 0, best_max = INT_MIN;
        for(auto x: nums){
            current_max = max(smallest, current_max + x);
            best_max = max(current_max, best_max);
            if(current_max < 0){
                current_max = 0;
            }
        }
        return best_max;
        //dynamic Programming:
        // vector<int> dp(nums.size());
        // int sum = 0;
        // dp[0] = nums[0];
        // for(int i = 1; i < nums.size(); i++){
        //     dp[i] = max(nums[i], nums[i]+dp[i-1]);
        // }
        // sort(dp.begin(), dp.end());
        // return dp[nums.size()-1];
    }
};
