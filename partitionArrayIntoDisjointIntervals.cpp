class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        if(nums.size()==2)
            return 1;
        int curMax = nums[0];
        int prevMax = nums[0];
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < prevMax){
                prevMax = curMax;
                index = i;
            }
            else
                curMax = max(curMax, nums[i]);
        }
        return index+1;
    }
};
