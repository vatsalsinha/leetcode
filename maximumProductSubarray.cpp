class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //kadane's algorithm
        int lastMax = nums[0], lastMin = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int tmp = max({nums[i], nums[i]*lastMax, nums[i]*lastMin});
            lastMin = min({nums[i], nums[i]*lastMax, nums[i]*lastMin});
            lastMax = tmp;
            ans = max(lastMax, ans);
        }
        return ans;
    }
};
