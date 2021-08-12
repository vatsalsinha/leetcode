class Solution {
public:
    int findParent(vector<int>& parent, int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent, parent[node]);
    }
    void unian(vector<int>& parent, vector<int>& rank, int u, int v){
        u = findParent(parent, u);
        v = findParent(parent, v);
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v])
            parent[v] = u;
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    void makeSet(vector<int>& parent, int n){
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n+1);
        makeSet(parent, n);
        vector<int> rank(n+1);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isConnected[i][j])
                    unian(parent, rank, i, j);
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(i == parent[i])
                count++;
        }
        return count;
    }
};
