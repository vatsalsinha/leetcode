class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        sum -= x;
        int ans = 0;
        if(sum == 0)
            return nums.size();
        int j = 0, temp_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            temp_sum += nums[i];
            //calculating the max subarray with sum = totSum_array - x
            while(j < nums.size() && sum < temp_sum){
                temp_sum -= nums[j++];
            }
            if(temp_sum == sum)
                ans = max(ans, i-j+1);
        }
        if(!ans)
            return -1;
        return nums.size()-ans;
    }
};
