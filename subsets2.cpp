class Solution {
public:
    void backtrack(set<vector<int>> &ans, vector<int> &res, vector<int> nums, int index){
        ans.insert(res);
        for(int i = index; i < nums.size(); i++){
            res.push_back(nums[i]);
            backtrack(ans, res, nums, i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        set<vector<int>> ans;
        backtrack(ans, res, nums, 0);
        vector<vector<int>> a(ans.begin(), ans.end());
        return a;
    }
};
