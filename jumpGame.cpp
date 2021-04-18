class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1){
            return true;
        }
        int max_index = nums[0];
        int current = nums[0], maxReach= nums[0];
        for(int i = 1; i < nums.size() && i <= max_index; i++){ //i<=max_index -> OP part
            max_index = max(max_index, nums[i] + i);
            if(max_index >= nums.size()-1){
                return true;
            }
        }
        return false;
    }
};
