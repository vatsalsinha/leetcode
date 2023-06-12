class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i = 0;
        int st = -1, en = -1;
        vector<string> ans;
        while(i < nums.size()){
            st = en+1;
            while(i+1 < nums.size() && nums[i+1]==nums[i]+1)
                i++;
            en = i;
            string s = en != st ? to_string(nums[st]) + "->" + to_string(nums[en]) : to_string(nums[st]);
            ans.push_back(s);
            i++;
        }
        return ans;
    }
};
