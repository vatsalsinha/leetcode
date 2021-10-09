class Solution {
public:
    // // void backtrack(set<vector<int>> &ans, vector<int>& res, vector<int> nums, int index){
    // //     ans.insert(res);
    // //     for(int i = index; i < nums.size(); i++){
    // //         res.push_back(nums[i]);
    // //         backtrack(ans, res, nums, i+1);
    // //         res.pop_back();
    // //     }
    // // }
    // void findSubsets(vector<int>& nums, int n, int index, vector<int> tmp, vector<vector<int>>& ans, int sz){
    //     if(index == n){
    //         ans.push_back(tmp);
    //         return;
    //     }
    //     tmp.push_back(nums[index]);
    //     findSubsets(nums, n, index+1, tmp, ans, sz+1);
    //     tmp.pop_back();
    //     findSubsets(nums, n, index+1, tmp, ans, sz);
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
//         // sort(nums.begin(), nums.end());
//         // set<vector<int>> ans;
//         // vector<int> res;
//         // backtrack(ans, res, nums, 0);
//         // vector<vector<int>> a(ans.begin(), ans.end());
//         // return a;
        
//         vector<vector<int>> ans;
//         vector<int> tmp;
//         int n = nums.size();
//         findSubsets(nums, n, 0, tmp, ans, 0);
//         return ans;
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < pow(2,n); i++){
            vector<int> tmp;
            for(int j = 0; j < n; j++){
                if(i & 1<<j){
                    tmp.push_back(nums[j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};