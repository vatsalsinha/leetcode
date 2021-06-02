class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int window = INT_MAX;
        int sum = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= target){
                window = min(window, i-j+1);
                sum -= nums[j];
                j++;
            }
        }
        return window == INT_MAX ? 0 : window;
    }
};
