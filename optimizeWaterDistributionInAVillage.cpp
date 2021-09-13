class Solution {
public:
    vector<int> parent, rank;
    int findParent(int n){
        if(parent[n] == n)
            return n;
        return n = findParent(parent[n]);
    }
    void unian(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u != v){
            if(rank[u] < rank[v]){
                parent[u] = v;
            } 
            else if(rank[v] < rank[u]){
                parent[v] = u;
            }
            else{
                parent[u] = v;
                rank[v]++;
            }
        }
    }
    
    void makeSet(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        parent.resize(n+1);
        rank.resize(n+1);
        makeSet(n+1);
        for (int i = 1; i <= n; ++i)
            pipes.push_back({0, i, wells[i-1]});
        sort(pipes.begin(), pipes.end(), [](auto& a, auto& b){ return a[2] < b[2]; });
        int ans = 0;
        for (auto& pipe : pipes) {
            if (findParent(pipe[0]) != findParent(pipe[1])) {
                ans += pipe[2];
                unian(pipe[0], pipe[1]);
            }
        }
        return ans;
    }
};
