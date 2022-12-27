class Solution {
public:
    vector<int> parent, rank;
    
    int findParent(int node){
        if(node == parent[node])
            return node;
        return node = findParent(parent[node]);
    }
    int unian(int u, int v, int count){
        u = findParent(u);
        v = findParent(v);
        if(u!=v){
            if(rank[u] > rank[v]){
                parent[v] = u;
            }
            else if(rank[u] < rank[v]){
                parent[u] = v;
            }
            else{
                parent[u] = v;
                rank[v]++;
            }
            count--;
        }
        return count;
    }
    void makeSet(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        makeSet(n);
        int count = n;
        for(int i = 0; i < edges.size(); i++){
            count = unian(edges[i][0], edges[i][1], count);
        }
        return count;
    }
};
