class Solution {
public:
    vector<int> parent, rank;
    int findParent(int node){
        if(node == parent[node])
            return node;
        return node = findParent(parent[node]);
    }
    long long unian(int u, int v, long long count){
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
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        makeSet(n);
        int count = n;
        for(int i = 0; i < edges.size(); i++){
            count = unian(edges[i][0], edges[i][1], count);
        }
        unordered_map<int, long long> mp;
        for(int i = 0; i < n; i++){
            mp[findParent(i)]++;
        }
        long long numberOfPaths = 0;
        long long remainingNodes = n;
        for (auto component : mp) {
            int componentSize = component.second;
            numberOfPaths += componentSize * (remainingNodes - componentSize);
            remainingNodes -= componentSize;
        }
        return numberOfPaths;
    }
};
