class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // if(nums.size() == 1){
        //     return k == nums[0];
        // }
        // int n = nums.size();
        // int prefixSum[n+1];
        // prefixSum[0] = 0;
        // for(int i = 0; i < n; i++){
        //     prefixSum[i+1] = prefixSum[i] + nums[i];
        // }
        // // sum[i....k] = sum[k] - sum[i-1];
        // int ans = 0;
        // unordered_map<int, int> mp;
        // mp[0] = -1;
        // for (int i = 1; i <= n; i++) {
        //     if (mp.find(prefixSum[i] - k) != mp.end())
        //         ans = max(ans, i - mp[prefixSum[i] - k]);
        //     if (mp.find(prefixSum[i]) == mp.end()) // keep only 1st duplicate as we want first index as left as possible
        //         mp[prefixSum[i]] = i;
        // }
        // return ans;
        
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i-1];
        unordered_map<int, int> mp;
        int n = nums.size();
        int ans = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i] - k) != mp.end())
                ans = max(ans, i - mp[nums[i] - k]);
            if (mp.find(nums[i]) == mp.end()) // keep only 1st duplicate as we want first index as left as possible
                mp[nums[i]] = i;
        }
        return ans;
    }
};
