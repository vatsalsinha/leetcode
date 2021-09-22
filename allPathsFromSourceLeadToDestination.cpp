class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, int destination){
        if(adj[node].empty())
            return node == destination;
        if(visited[node] != -1) // for cycle detection
            return visited[node];
        visited[node] = 0;
        for(auto e : adj[node]){
            if(!dfs(e, adj, visited, destination))
                return false;
        }
        return visited[node] = 1;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n, -1);
        vector<vector<int>> adj(n);
        int last = -1;
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }
        return dfs(source, adj, visited, destination);
    }
};
