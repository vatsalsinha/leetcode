class Solution {
public:
    int jump(vector<int>& nums) {
        // if current == i, then jump has occurred. 
        int jumps = 1, maxReach = nums[0], current = nums[0];
        if(nums.size() == 0 || nums.size() == 1){
            return 0;
        }
        for(int i = 1; i < nums.size(); i++){
            if(i == nums.size()-1){
                return jumps;
            }
            maxReach = max(maxReach, nums[i]+i);
            if(i == current){
                jumps++;
                current = maxReach;
            }
        }
        return jumps;
    }
};
