class Solution {
public:
    void findCombinations(int index, int last, vector<int> nums, vector<vector<int>> &ans, vector<int> &ds){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        int i = 0;
        for(int i = index; i < last+1; i++){
            swap(nums[i], nums[index]);
            findCombinations(index+1, last, nums, ans, ds);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1){
            vector<vector<int>> res;
            res.push_back({nums[0]});
        }
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, nums.size()-1, nums, ans, ds);
        return ans;
    }
};
