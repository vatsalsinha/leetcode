class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int i = 0, j = 1;
        // int sum = 0;
        // while(i < nums.size() && j < nums.size()){
        //     sum += min(nums[i], nums[j]);
        //     i += 2;
        //     j += 2;
        // }
        // return sum;
        sort(nums.begin(), nums.end());
        int sum  = 0;
        for(int i = 0; i < nums.size(); i += 2){
            sum += nums[i];
        }
        return sum;
    }
};
