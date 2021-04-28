class Solution {
public:
    void backtrack(int n, int k, vector<vector<int>> &ans, vector<int> &res, int index){
        if(res.size() == k){
            ans.push_back(res);
            return;
        }
        for(int i = index; i < n+1; i++){
            res.push_back(i);
            backtrack(n, k, ans, res, i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        backtrack(n,k,ans,res,1);
        return ans;
    }
};