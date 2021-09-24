class Solution {
public:
    //Dijkstra algorithm:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1]; //node:dist;
        for(auto t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; // dist:node
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int dst = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            for(auto it : adj[prev]){
                int next = it.first;
                int nextDist = it.second;
                if(nextDist + dist[prev] < dist[next]){
                    dist[next] = nextDist + dist[prev];
                    pq.push({dist[next], next});
                }
            }
        }
        int a = *max_element(dist.begin()+1, dist.end()); // since dist[0] is always INT_MAX && n => [1,100]
        return a == INT_MAX ? -1 : a;
    }
};