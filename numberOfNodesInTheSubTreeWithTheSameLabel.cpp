class Solution {
public:
    vector<int> dfs(vector<vector<int>>& graph, string& labels, int current, int parent, vector<int>& ans){
        vector<int> v(26,0);
        v[labels[current] - 'a'] = 1;
        for(auto e : graph[current]){
            if(e == parent)
                continue;
            auto f = dfs(graph, labels, e, current, ans);
            for (int i = 0; i < 26; i++) {
                v[i] += f[i];
            }
        }
        ans[current] = v[labels[current] - 'a'];
        return v;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> ans(n, 0);
        dfs(graph, labels, 0, -1, ans);
        return ans;
    }
};
