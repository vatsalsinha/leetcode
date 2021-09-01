class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_set<int> ans;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(ans.count(nums[i]) > 0)
                continue;
            int k = i;
            int tmp_max = 0;
            while(ans.count(nums[k]) == 0){
                ans.insert(nums[k]);
                tmp_max++;
                k = nums[k];
            }
            res = max(tmp_max, res);
        }
        return res;
    }
};
