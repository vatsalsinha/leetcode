class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<int> dist(n, INT_MAX);
        unordered_map<int, unordered_map<int, int>> g;
        for(auto e : edges){
            g[e[0]][e[1]] = g[e[1]][e[0]] = e[2] + 1;
        }
       auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){ return a.second > b.second; };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            auto u = pq.top().first;
            pq.pop();
            if(dist[u] >= maxMoves)
                break;
            for(auto n : g[u]){
                int v = n.first, w = n.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = w + dist[u];
                    pq.push({v, dist[v]});
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(dist[i] <= maxMoves)
                res++;
        }
        for(auto e : edges){
            int a = dist[e[0]] >= maxMoves ? 0 : min(maxMoves- dist[e[0]], e[2]);
            int b = dist[e[1]] >= maxMoves ? 0 : min(maxMoves - dist[e[1]], e[2]);
            res += min(a+b, e[2]);
        }
        return res;
    }
};
