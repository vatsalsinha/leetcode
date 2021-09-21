class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int x, int y){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid.size()  && grid[x][y] == 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1},{-1,-1},{1,1}};
        queue<pair<int, int>> q;
        q.push({0,0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        grid[0][0] = 1;
        while(!q.empty()){
            auto x = q.front();
            cout<<x.first<<":"<<x.second<<"\n";
            if(x.first == n-1 && x.second == n-1)
                return grid[x.first][x.second];
            q.pop();
            for(auto dir : directions){
                int X = x.first + dir[0];
                int Y = x.second + dir[1];
                if(isValid(grid, X,Y)){
                    q.push({X,Y});
                    grid[X][Y] = grid[x.first][x.second]+1; 
                }
            }
        }
        return -1;
    }
};
