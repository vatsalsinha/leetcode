class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int &islandId){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 0)
            return 0;
        grid[i][j] = islandId;
        return 1 + dfs(grid, i+1, j, islandId) + dfs(grid, i-1, j, islandId) + dfs(grid, i, j+1, islandId) + dfs(grid, i, j-1, islandId);
    }
    
    bool check(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
        if(grid[i][j] == 1)
            return true;
        grid[i][j] = 1;
        bool b1 = check(grid, i+1, j);
        bool b2 = check(grid, i-1, j);
        bool b3 = check(grid, i, j+1);
        bool b4 = check(grid, i, j-1);
        return b1 && b2 && b3 && b4;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int islandId = 2, count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0){
                    dfs(grid, i, j, islandId);
                    islandId++;
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 1)
                    count += check(grid, i, j) ? 1 : 0;
            }
        }
        return count;
    }
};
