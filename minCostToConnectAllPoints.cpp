//KRUSKAL's Algorithm

class Solution {
public:
    struct node{
        int u; int v; int wt;
        node(int f, int s, int t){
            u = f;
            v = s;
            wt = t;
        }
    };
    bool static cmp(node a, node b){
        return a.wt < b.wt;
    }
    int getDistance(vector<int> a, vector<int> b){
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
    int findParent(int node, vector<int>& parent){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node], parent);
    }
    void unian(int u, int v, vector<int>& parent, vector<int>& rank){
        u = findParent(u, parent);
        v = findParent(v, parent);
        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[u] > rank[v])
            parent[v] = u;
        else{
            parent[u] = v;
            rank[v]++;
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<node> adj;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                adj.push_back(node(i, j, getDistance(points[i], points[j])));
            }
        }
        sort(adj.begin(), adj.end(), cmp);
        int cost = 0;
        vector<int> parent(points.size());
        for(int i = 0; i < points.size(); i++) 
	        parent[i] = i; 
        vector<int> rank(points.size(), 0);
        for(auto it : adj){
            if(findParent(it.v, parent) != findParent(it.u, parent)){
                cost += it.wt;
                unian(it.u, it.v, parent, rank);
            }
        }
        return cost;
    }
};
