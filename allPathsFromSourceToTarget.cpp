class Solution {
public:
    void dfs(vector<vector<int>> graph, int curNode, vector<int>& res, vector<vector<int>> & ans){
        res.push_back(curNode);
        if(curNode == graph.size()-1){
            ans.push_back(res);
            return;
        }
        for(auto node : graph[curNode]){
            dfs(graph, node, res, ans);
            res.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(graph, 0, res, ans);
        return ans;
    }
};
