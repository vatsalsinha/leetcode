class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int duplicate;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                duplicate = nums[i];
                break;
            }
        }
        int sum = (nums.size()*(nums.size()+1))/2;
        for(int i = 0; i < nums.size(); i++){
            sum -= nums[i];
        }
        return {duplicate, sum+duplicate};
    }
};
