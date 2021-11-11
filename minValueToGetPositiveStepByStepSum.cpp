class Solution {
public:
    int minStartValue(vector<int>& nums) {
        vector<int> prefixSum(nums.size()+1,0);
        for(int i = 1; i <= nums.size(); i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        int ans = *min_element(prefixSum.begin(), prefixSum.end());
       return 1 - ans;
    }
};

// -3 -1 -4 0 2
// 1 2
// 1 -1 -4
