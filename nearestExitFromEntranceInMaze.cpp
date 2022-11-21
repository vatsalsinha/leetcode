class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int, pair<int, int>>> q; // x,y,dist
        int m = maze.size(), n = maze[0].size();
        q.push({entrance[0], {entrance[1], 0}});
        maze[entrance[0]][entrance[1]] = '+';
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            for(auto dir : dirs){
                int x = tmp.first + dir.first;
                int y = tmp.second.first + dir.second;
                if(0 <= x && x < m && 0 <= y && y < n && maze[x][y] == '.'){
                    if(x == 0 || x == m-1 || y == 0 || y == n-1)
                        return tmp.second.second + 1;
                    maze[x][y] = '+';
                    q.push({x, {y, tmp.second.second+1}});
                }
            }
        }
        return -1;
    }
};
