class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(int i = 0; i < roads.size(); i++){
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<bool> vis(n+1,0);
        queue<int> q;
        q.push(1);
        int ans = INT_MAX;
        vis[1] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& e : graph[node]){
                ans = min(ans, e.second);
                if(!vis[e.first]){
                    vis[e.first] = 1;
                    q.push(e.first);
                }
            }
        }
        return ans;
    }
};
