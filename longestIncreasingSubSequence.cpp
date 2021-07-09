class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp
        vector<int> dp(nums.size());
        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < nums.size(); i++){
            int m = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    m = max(m, dp[j]);
                }
            }
            dp[i] = m + 1;
            ans = max(dp[i], ans);
        }
        return ans;
        
        /*  O(nlogn)
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end())
                res.push_back(nums[i]);
            else
                *it = nums[i]; //It's getting updated by reference, *it = num[i], the position it currently points to gets updated with value num[i] and in next iteration, it will store new location for new num[i].
        }
        return res.size();
        */
    }
};
