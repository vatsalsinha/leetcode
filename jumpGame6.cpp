class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        // does not work for very outputs
        // vector<int>dp(nums.size(),INT_MIN);
        // dp[0] = nums[0];
        // for(int i = 1;i<nums.size();i++){
        //     int l = k;
        //     while(l){
        //         if(i-l>=0){
        //             dp[i] = max(dp[i-l]+nums[i],dp[i]);     
        //         }
        //         l--;
        //     }
        // }
        // return dp[nums.size()-1];
        deque<int> q;
        vector<int> dp(nums.size());
        dp[nums.size()-1] = nums[nums.size()-1];
        q.push_back(nums.size()-1);
        for(int i = nums.size()-2; i > -1; i--){
            if(q.front() - i > k)
                q.pop_front();
            dp[i] = nums[i] + dp[q.front()];
            while(q.size() && dp[q.back()] < dp[i])
                q.pop_back();
            q.push_back(i);
        }
        return dp[0];
    }
};
