class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int size = nums.size();
        int leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> result(size, 0);
        for (int i = 0; i < size; i++) {
            rightSum -= nums[i];
            leftSum += nums[i];
            result[i] += nums[i] * (i + 1) - leftSum + rightSum - nums[i] * (size - i - 1);
        }
        return result;
    }
};
