class Solution {
public:
    /* DFS solution
    bool dfs(unordered_map<int, vector<int>>&m, int node, vector<int> visited, int parent){
        if(find(visited.begin(), visited.end(), node) != visited.end())
            return true;
        visited.push_back(node);
        for(int v : m[node]){
            if(v == parent)
                continue;
            if(dfs(m, v, visited, node))
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        vector<int> visited;
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < edges.size(); i++){
            int f = edges[i][0];
            int s = edges[i][1];
            m[f].push_back(s);
            m[s].push_back(f);
            if(dfs(m, f, visited, -1))
                return {f,s};
            visited.clear();
        }
        return {};
    }
    */
    
    // UnionFind solution
    /*
     * Find the subset a vertex belongs to.
     finds parent of x
     */
    int findParent(vector<int>& e, int x){
        if(e[x] == -1)
            return x;
        return e[x] = findParent(e, e[x]); // path compression
    }
    /*
     * Unionize two subsets. 
     */
    void _union(vector<int>& e, int x, int y){
        int xp = findParent(e, x);
        int yp = findParent(e, y);
        if(xp != yp) // union should be performed
            e[yp] = xp;
    }
     /*
     * We use disjoint set (or Union-Find) to detect a cycle in
     * an undirected graph.
     */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        /* Create parent subsets and initialize them to -1 - this means
         * the subsets contain only one item - i.e ss[i] only contains
         * vertex i.
         */
        vector<int> e(edges.size()+1, -1);
        /*
         * We go through each edge one by one. We find the subset
         * that the vertices of an edge belongs to. If they belong
         * to two different subsets, we merge them into one set 
         * using Union. Now, if both vertices are in the same 
         * subset, we got a cycle - we return it.
         *
         */
        for(int i = 0; i < edges.size(); i++){
            int x = findParent(e, edges[i][0]);
            int y = findParent(e, edges[i][1]);
            if(x == y) // there exists a cycle
                return {edges[i][0], edges[i][1]};
            _union(e, x, y);
        }
        // no edge found
        return {};
    }
};