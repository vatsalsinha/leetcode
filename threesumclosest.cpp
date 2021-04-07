class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum, diff = INT_MAX, low, high;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            low = i+1;
            high = nums.size()-1;
            while(low < high){
                sum = nums[i] + nums[low] + nums[high];
                if(abs(target-sum) < abs(diff)){
                    diff = target - sum;
                }
                if(sum < target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        return target-diff;
    }
};
