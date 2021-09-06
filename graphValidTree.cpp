class Solution {
public:
    vector<int> parent, rank;
    int findParent(int n){
        if(n == parent[n])
            return n;
        return parent[n] = findParent(parent[n]);
    }
    bool sameParent(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u != v){
            if(rank[u] > rank[v])
                parent[v] = u;
            else if(rank[u] < rank[v])
                parent[u] = v;
            else{
                parent[v] = u;
                rank[u]++;
            }
            return true;
        }
        return false;
    }
    void makeSet(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // int  = edges.size();
        parent.resize(n);
        rank.resize(n);
        makeSet(n);
        for(int i = 0; i < edges.size(); i++){
            if(!sameParent(edges[i][0], edges[i][1]))
                return false;
        }
        return edges.size() == n-1;
        
    }
};
