class Solution {
public:
    int dist[100001];
    int ans = 1;
    void dfs(vector<vector<int>>& graph, int curr, string& s){
        dist[curr] = 1;
        for(auto e : graph[curr]){
            dfs(graph, e, s);
            if(s[e] != s[curr]){
                ans = max(ans, dist[curr] + dist[e]);
                dist[curr] = max(dist[curr], dist[e]+1); 
            }
        }
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);
        for(int i = 1; i < n; i++){
            graph[parent[i]].push_back(i);
        }
        dfs(graph, 0, s);
        return ans;
    }
};

