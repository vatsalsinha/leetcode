class Solution {
public:
    int backtrack(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= 0)
            return 0;
        //int val = grid[i][j];
        grid[i][j] = -grid[i][j];
        auto res = max({backtrack(grid,i+1,j) , backtrack(grid,i-1,j) , backtrack(grid,i,j-1) , backtrack(grid,i,j+1)});
        grid[i][j] = -grid[i][j];
        return res + grid[i][j];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0){
                    maxGold = max(maxGold, backtrack(grid, i, j));
                }
            }
        }
        return maxGold;
    }
};
