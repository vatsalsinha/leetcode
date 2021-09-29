class Solution {
public:
    bool isValid(int x, int y, int m, int n){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        dist[0][0] = 0;
        while(!pq.empty()){
            int x = pq.top()[0];
            int y = pq.top()[1];
            int w = pq.top()[2];
            pq.pop();
            for(auto dir : directions){
                int X = x + dir[0];
                int Y = y + dir[1];
                if(isValid(X, Y, m, n) && dist[X][Y] > max(w, abs(heights[X][Y] - heights[x][y]))){
                    dist[X][Y] = max(w, abs(heights[X][Y] - heights[x][y]));
                    pq.push({X,Y,dist[X][Y]});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
