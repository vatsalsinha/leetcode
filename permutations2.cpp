class Solution {
public:
    /*
        void findCombinations(int index, int last, vector<int> nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        int i = 0;
        for(int i = index; i < last+1; i++){
            swap(nums[i], nums[index]);     
            findCombinations(index+1, last, nums, ans);
            swap(nums[i], nums[index]);
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 1){
            vector<vector<int>> res;
            res.push_back({nums[0]});
        }
        vector<vector<int>> ans;
        findCombinations(0, nums.size()-1, nums, ans);
        set<vector<int>> s(ans.begin(), ans.end());
        ans.assign(s.begin(), s.end());
        return ans;
    }
    */
    void findCombinations(int index, int last, vector<int> nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        int i = 0;
        for(int i = index; i < last+1; i++){
            if(i!=index && nums[i] == nums[index]){
                continue;
            }
            swap(nums[i], nums[index]);     
            findCombinations(index+1, last, nums, ans);            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 1){
            vector<vector<int>> res;
            res.push_back({nums[0]});
        }
        vector<vector<int>> ans;
        findCombinations(0, nums.size()-1, nums, ans);
        return ans;
    }
};

