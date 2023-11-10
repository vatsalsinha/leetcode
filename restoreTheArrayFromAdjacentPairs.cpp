class Solution {
public:
    unordered_set<int> vis;
    void dfs(int node, unordered_map<int, vector<int>>& graph, vector<int>& ans){
        vis.insert(node);
        ans.push_back(node);
        for(int i : graph[node]){
            if(vis.count(i) == 0)
                dfs(i, graph, ans);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        for(auto e : adjacentPairs){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int start = 0;
        for(auto it : graph){
            if(it.second.size() == 1){
                start = it.first; 
                break;
            }
        }
        vector<int> ans;
        dfs(start, graph, ans);
        return ans;
    }
};
