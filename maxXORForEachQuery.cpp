class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        //approach 1
        vector<int> preXOR(nums.size(),0);
        int m = pow(2, maximumBit)-1; // max value after xor operation
        preXOR[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            preXOR[i] = preXOR[i-1]^nums[i];
        }
        //vector<int> ans; // use nums or initialize another vector to store
        for(int i = 0; i < nums.size(); i++)
            nums[i] = m ^ preXOR[nums.size()-i-1];
        //reverse(nums.begin(), nums.end());
        return nums;
        //approach 2
        // int m = pow(2,maximumBit)-1;
        // vector<int> ans(nums.size());
        // for(int i = 0; i < nums.size(); i++){
        //     ans[nums.size()-i-1] = m ^= nums[i];
        // }
        // return ans;
    }
};