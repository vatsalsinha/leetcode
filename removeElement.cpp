class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size()-1;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] == val){
                // if(nums.begin()+i == nums.end() && nums[i] == val){
                //     nums.pop_back();
                // }
                // else{
                    nums.erase(nums.begin()+i);
                // }
            }
        }
        return nums.size();
    }
};
