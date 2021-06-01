class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // int sum = 0, leftSum = 0;
        // for(auto n : nums)
        //     sum += n;
        // for(int i = 0; i < nums.size(); i++){
        //     if(leftSum == sum - leftSum - nums[i])
        //         return i;
        //     leftSum += nums[i];
        // }
        // return -1;
        if(nums.size() == 0)
            return -1;
        if(nums.size() == 1)
            return 0;
        int sum = 0;
        for(int n : nums){
            sum += n;
        }
        int leftSum = 0, rightSum = sum - nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i > 0){
                leftSum += nums[i-1];
                rightSum -= nums[i];
            }
            if(leftSum == rightSum)
                return i;
        }
        return -1;
    }
};