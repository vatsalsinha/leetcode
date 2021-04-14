class Solution {
public:
    void findCombinations(int index, int target, vector<int> arr, vector<vector<int>> &ans, vector<int> &ds){
        if(index == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(arr[index] <= target){
            ds.push_back(arr[index]);
            findCombinations(index, target-arr[index], arr, ans, ds);
            ds.pop_back();
        }
        findCombinations(index+1, target, arr, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};
