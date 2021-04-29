class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3){
            return nums.size();
        }    
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i-1] == nums[i+1]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
        // if(nums.size() < 3){
        //     return nums.size();
        // }
        // int ind = 0;
        // int count = 1;
        // for(int i = 1; i < nums.size(); i++){
        //     if((nums[i-1] == nums[i]) && count < 2){
        //         nums[ind++] = nums[i];
        //         count++;
        //     }
        //     else if(nums[i-1] != nums[i]){
        //         count = 1;
        //         nums[ind++] = nums[i-1]; 
        //     }
        // }
        // nums[ind] = nums[nums.size()-1];
        // return ind+1;
    }
};
