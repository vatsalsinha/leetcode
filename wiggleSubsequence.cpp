class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int up[nums.size()], down[nums.size()];
        if(nums.size() < 2)
            return nums.size();
        up[0] = down[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } // increasing wiggle sequence
            else if(nums[i] < nums[i-1]){
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            } // decreasing wiggle sequence
            else{
                up[i] = up[i-1];
                down[i] = down[i-1];
            } // no wiggle sequence
        }
        return max(up[nums.size()-1], down[nums.size()-1]);
    }
};
/* 
If nums[i] > nums[i-1]nums[i]>nums[i−1], that means it wiggles up. The element before it must be a down position. So up[i] = down[i-1] + 1up[i]=down[i−1]+1, down[i]down[i] remains the same as down[i-1]down[i−1]. 
If nums[i] < nums[i-1]nums[i]<nums[i−1], that means it wiggles down. The element before it must be a up position. So down[i] = up[i-1] + 1down[i]=up[i−1]+1, up[i]up[i] remains the same as up[i-1]up[i−1]. 
If nums[i] == nums[i-1]nums[i]==nums[i−1], that means it will not change anything becaue it didn't wiggle at all. So both down[i]down[i] and up[i]up[i] remain the same as down[i-1]down[i−1] and up[i-1]up[i−1].
*/
