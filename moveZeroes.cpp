class Solution {
public:
    void moveZeroes(vector<int>& nums) {
//         vector<int> res(nums.size(), 0);
//         int ind = 0;
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] != 0){
//                 res[ind] = nums[i];
//                 ind++;
//             }
                
//         }
//         nums = res;
            int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0)
                nums[index++] = nums[i];
        }
        for(int i = index; i < nums.size(); i++)
            nums[i] = 0;
    }
};
