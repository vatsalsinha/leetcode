class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(n) space
        // int count = 0;
        // for(int i = 0; i < nums.size(); i++)
        //     count += nums[i] == 0;
        // if(count > 1){
        //     return vector<int>(nums.size(), 0);
        // }
        // vector<int> left(nums.size());
        // vector<int> right(nums.size());
        // left[0] = nums[0];
        // right[nums.size()-1] = nums.back();
        // for(int i = 1; i < nums.size(); i++){
        //     left[i] = left[i-1] * nums[i];
        // }
        // for(int i = nums.size()-2; i > -1; i--){
        //     right[i] = right[i+1] * nums[i];
        // }
        // vector<int> ans(nums.size());
        // ans[0] = right[1];
        // ans[nums.size()-1] = left[nums.size()-2];
        // for(int i = 1; i < nums.size()-1; i++){
        //     ans[i] = left[i-1] * right[i+1];
        // }
        // return ans;
        
        // o(1) space:
        vector<int> ans(nums.size());
        int r = 1;
        ans[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        //int r = 1;
        for(int i = nums.size()-1; i > -1; i--){
            ans[i] *= r;
            r *= nums[i];
        }
        return ans;
        
    }
};
