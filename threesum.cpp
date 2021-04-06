class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
             vector<vector<int>> res = {};
            return res;
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int low, high, sum;
        for(int i = 0; i < nums.size()-2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                sum = 0 - nums[i];
                low = i+1;
                high = nums.size()-1;
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[low] == nums[high-1]) high--;
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] > sum) {
                        high--;
                    }
                    else{
                        low++;
                    }
                }
            }
        }
        return ans;
    }
};
