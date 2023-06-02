class Solution {
public:
    int dfs(int i, unordered_set<int>& vis, vector<vector<int>>& graph){
        vis.insert(i);
        for(auto node : graph[i]){
            if(vis.count(node) == 0)
                dfs(node, vis, graph);
        }
        return vis.size();
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        if(bombs.size() == 1)
            return 1;
        vector<vector<int>> graph(bombs.size());
        for(int i = 0; i < bombs.size(); i++){
            for(int j = 0; j < bombs.size(); j++){
                int xi = bombs[i][0];
                int yi = bombs[i][1];
                int ri = bombs[i][2];
                int xj = bombs[j][0];
                int yj = bombs[j][1];
                if((long long)ri*ri >= ((long long)(xi-xj)*(xi-xj) + (long long)(yi-yj)*(yi-yj)))
                    graph[i].push_back(j);
            }
        }
        int ans = 0;
        for(int i = 0; i < bombs.size(); i++){
            unordered_set<int> vis;
            ans = max(ans, dfs(i, vis, graph));
        }
        return ans;
    }
};
