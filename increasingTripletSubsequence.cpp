class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int preMax[n];
        int sufMax[n];
        preMax[0] = nums[0];
        sufMax[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
            preMax[i] = min(preMax[i-1], nums[i]);
        }
        for(int i = n-2; i > -1; i--){
            sufMax[i] = max(sufMax[i+1], nums[i]);
        }
        for(int i = 1; i < n-1; i++)
            if(nums[i] > preMax[i-1] && nums[i] < sufMax[i+1])
                return 1;
        return 0;
    }
};
