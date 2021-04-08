class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() == 0 || nums.size()  < 4){
             vector<vector<int>> res = {};
            return res;
        }
        sort(nums.begin(), nums.end());
        int sum, high, higher, highest;
        set<vector<int>> ans;
        for(int i = 0; i < nums.size()-3; i++){
            for(int j = i+1; j < nums.size()-2; j++){
                higher = j+1;
                highest = nums.size()-1;
                while(higher < highest){
                    sum = nums[i] + nums[j] + nums[higher] + nums[highest];
                    if (sum == target){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[higher]);
                        tmp.push_back(nums[highest]);
                        ans.insert(tmp);
                        while(higher < highest && nums[higher] == nums[higher+1]) higher++;
                        while(higher < highest && nums[higher] == nums[highest-1]) highest--;     
                        higher++;
                        highest--;
                    }
                    else if(sum > target) {
                        highest--;
                    }
                    else{
                        higher++;
                    }
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
