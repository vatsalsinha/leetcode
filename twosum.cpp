class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> res;
        for(int i = 0; i < nums.size(); i++){
            if(res.find(target - nums[i]) != res.end()){
                ans.push_back(i);
                ans.push_back(res[target-nums[i]]);
            }
            res[nums[i]] = i;
        }
        return ans;
    }
};
