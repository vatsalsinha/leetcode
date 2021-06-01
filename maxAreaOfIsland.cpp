class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& seen, int i, int j, int r, int c){
        if(i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0 || seen[i][j] == true)
            return 0;
        seen[i][j] = true;
        return 1 + dfs(grid, seen, i+1, j, r, c) + dfs(grid, seen, i-1, j, r, c) + dfs(grid, seen, i, j+1, r, c) + dfs(grid, seen, i, j-1, r, c); 
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j  = 0; j < grid[0].size(); j++){
                if(grid[i][j])
                    ans = max(ans, dfs(grid, seen, i, j, grid.size(), grid[0].size()));
            }
        }
        return ans;
    }
};
