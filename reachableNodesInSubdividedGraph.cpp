class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> g(n);
        for(auto e : edges){
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
	//dijkstra starts
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0}); // node:weight
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        while(!pq.empty()){
            int u = pq.top().first;
            int w = pq.top().second;
            pq.pop();
            for(auto i : g[u]){
                if(dist[i.first] > w + i.second + 1){
                    dist[i.first] = w + i.second + 1;
                    pq.push({i.first, dist[i.first]});
                }
            }
        }
	//dijsktra ends
        int ans = 0;
        for(int i = 0; i < n; i++){ // reachable nodes that are present in the initial graph
            if(dist[i] <= maxMoves)
                ans++;
        }
        for(auto e : edges){ // reachable nodes that are added later to the graph
            int src = e[0], dst = e[1], bw = e[2];
            int x = max(0, (maxMoves - dist[src]));
            int y = max(0, (maxMoves - dist[dst]));
            ans += min(bw, x+y);
        }
        return ans;
    }
};