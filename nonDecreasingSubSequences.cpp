class Solution {
public:
    void backtrack(vector<int>& nums, set<vector<int>>& ans, vector<int> tmp, int pos){
        if(pos == nums.size()){
            if(tmp.size() >= 2){
                ans.insert(tmp);
            }
            return;
        }
        if(tmp.empty() || tmp.back() <= nums[pos]){
            tmp.push_back(nums[pos]);
            backtrack(nums, ans, tmp, pos+1);
            tmp.pop_back();
        }
        backtrack(nums, ans, tmp, pos+1);

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> tmp;
        backtrack(nums, ans, tmp, 0);
        return vector(ans.begin(), ans.end());
    }
};
