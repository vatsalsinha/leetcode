class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // idea is to have a vector of unordered_maps and store common Difference for each nums[i]
        vector<unordered_map<int, int>> m(nums.size()); // [{cd : numberOfOccurences}, {},.....]
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                long cd = (long)nums[i] - (long)nums[j];
                if(cd <= INT_MIN || cd >= INT_MAX)
                    continue;
                int apEndingOnJ = m[j][cd];
                int apEndingOnI = m[i][cd];
                ans += apEndingOnJ;
                m[i][(int)cd] = apEndingOnJ + apEndingOnI + 1;
            }
        }
        return ans;
    }
};
