class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if( i < 0 || j < 0 || i > grid.size()-1 || j > grid[0].size()-1 || !grid[i][j] || grid[i][j] == 2) 
            return 0 ; 
        grid[i][j] = 2; // visited
        int ans = 4;
        if(i < grid.size() - 1 && grid[i+1][j])
            ans--; 
        if(j < grid[0].size() -1 && grid[i][j+1])
            ans--;
        if(j > 0 && grid[i][j-1])
            ans--; 
        if(i > 0 && grid[i-1][j])
            ans--; 
        return ans + dfs(grid, i-1, j) + dfs(grid, i+1, j) + dfs(grid, i, j-1) + dfs(grid, i, j+1);
            
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j])
                    return dfs(grid, i, j);
            }
        }
        return 0;
    }
};
