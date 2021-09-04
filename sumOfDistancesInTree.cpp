class Solution {
public:
    vector<vector<int>> adj;
    vector<int> res, count;
    void preOrderDFS(int root, int parent){
        for(auto i : adj[root]){
            if(i == parent)
                continue;
            preOrderDFS(i, root);
            count[root] += count[i];
            res[root] += res[i] + count[i]; 
        }
        count[root]++;
    }
    void postOrderDFS(int root, int parent){
        for(auto i : adj[root]){
            if(i == parent)
                continue;
            res[i] = res[root] - count[i] + count.size() - count[i];
            postOrderDFS(i, root);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        res.resize(n);
        count.resize(n);
        preOrderDFS(0,-1);
        postOrderDFS(0, -1);
        return res;
    }
};
