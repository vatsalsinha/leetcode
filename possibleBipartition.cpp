class Solution {
public:
int parent[2001], rank[2001];
    int findParent(int u){
        if(u == parent[u])
            return parent[u];
        return parent[u] = findParent(parent[u]);
        
    }
    void unian(int x, int y) {
        int xset = findParent(x), yset = findParent(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        vector<vector<int>> adj(n + 1);
        for (auto& dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }
         for (int node = 1; node <= n; node++) {
            for (int neighbor : adj[node]) {
                if(findParent(node) == findParent(neighbor))
                    return 0;
                unian(adj[node][0], neighbor);
            }
         }
       return 1;
    }
};
