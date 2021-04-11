class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> ans;
        ans.insert(nums.begin(), nums.end());
        nums.erase(begin(nums),end(nums));
        nums.assign(ans.begin(), ans.end());
        return nums.size();
    }
};
