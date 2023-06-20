class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n+1);
        preSum[0] = 0;
        for(int i = 1; i < n+1; i++){
            preSum[i] = preSum[i-1] + nums[i-1];
        }
        vector<int> ans(nums.size(), -1);
        for(int i = 0; i < preSum.size(); i++){
            if((i-k) >= 1 && (i+k) < n+1){
                auto s = preSum[i+k]-preSum[i-k-1];
                ans[i-1] = s/(2*k+1);
            }
        }
        return ans;
    }
};
// 0 7 11 14 23 24 32 37 39 45
// 0 1 2  3  4. 5.  6. 7. 8. 9
