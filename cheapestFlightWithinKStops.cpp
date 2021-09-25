//Bellman ford algorithm
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e8); // stores cost using at most k-1 edges
        if(k == 0){
            for(auto f : flights){
                if(f[0] == src && f[1] == dst)
                    return f[2];
            }
            return -1;
        }
        dist[src] = 0;
        for(int i = 0; i < k+1; i++){ // k stops ie k+2 edges
            vector<int> d(dist); //stores cost using at most k edges
            for(auto e : flights){
                if(dist[e[0]] + e[2] < d[e[1]]){
                    d[e[1]] = dist[e[0]] + e[2];
                }
            }
            dist = d;
        }
        return dist[dst] == 1e8 ? -1 : dist[dst];
    }
};