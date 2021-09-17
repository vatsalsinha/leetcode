class Solution {
public:
    bool isValid(vector<vector<int>> grid, int x, int y, int m, int n){
        return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ones = 0;
        int ans = -1;
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    grid[i][j] = -2;
                }
                else if(grid[i][j] == 1)
                    ones++;
            }
        }
        if(ones == 0)
            return 0;
        vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto p = q.front();
                q.pop();
                for(auto dir : directions){
                    int x = p.first + dir[0];
                    int y = p.second + dir[1];
                    if(isValid(grid, x, y, m, n)){
                        grid[x][y] = 2;
                        q.push({x,y});
                        ones--;
                    }
                }
            }
            ans++;
        }
        if(ones > 0)
            return -1;
        if(ans == -1)
            return 0;
        return ans;
    }
};
