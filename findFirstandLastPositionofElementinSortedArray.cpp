class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int l = 0, r = nums.size()-1;
        int c = count(nums.begin(), nums.end(), target);
        c = c-1;
        int pos = -1;
        while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target)
            pos = m;

        if (nums[m] < target)
            l = m + 1;

        else
            r = m - 1;
    }
        if(pos != -1){
            ans.clear();
            ans.push_back(pos);
            ans.push_back(pos+c);
            return ans;
        }
        return ans;
    }
};
