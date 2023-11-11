class Graph {
public:
vector<vector<pair<int, int>>> g;
    Graph(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(int i = 0; i < edges.size(); i++){
            g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        //Dijkstra Algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(g.size(), INT_MAX);
        dist[node1] = 0;
        pq.push({0, node1});
        while(!pq.empty()){
            int dst = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for(auto it : g[prev]){
                int next = it.first;
                int nextDist = it.second;
                if(nextDist + dist[prev] < dist[next]){
                    dist[next] = nextDist + dist[prev];
                    pq.push({dist[next], next});
                }
            }
        }
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
