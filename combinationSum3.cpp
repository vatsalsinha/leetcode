class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& tmp, int k, int sum, int pos){
        if(tmp.size() == k && sum == 0){
            ans.push_back(tmp);
            return;
        }
        for(int i = pos; i < 10; i++){
            tmp.push_back(i);
            backtrack(ans, tmp, k, sum-i, i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(ans, tmp, k, n, 1);
        return ans;
    }
};
