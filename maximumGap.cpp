class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int minElement = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 2)
            return nums[n-1] - nums[0];
        if(n < 2)
            return 0;
        if(maxElement == minElement)
            return 0;
        int gap = (maxElement - minElement) / (n-1);
        if((maxElement - minElement) % (n-1) != 0)
            gap++;
        vector<int> minArray(n, INT_MAX), maxArray(n, INT_MIN);
        for(int i = 0; i < n; i++){
            int bkt = (nums[i] - minElement) / gap;
            minArray[bkt] = min(nums[i], minArray[bkt]);
            maxArray[bkt] = max(nums[i], maxArray[bkt]);
        }
        int ans = INT_MIN, prev = maxArray[0];
        for(int i = 0; i < n; i++){
            if(minArray[i] == INT_MAX)
                continue;
            else{
                ans = max(ans, minArray[i] - prev);
                prev = maxArray[i];
            }
        }
        return ans;
    }
};
