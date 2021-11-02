class Solution {
public:
    int empty = 1, res = 0; // empty == 1 cuz starting point is also empty
    void backtrack(vector<vector<int>>& grid, int x, int y, int count){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1){
            return;
        }
        if(grid[x][y] == 2){
            if(empty == count)
                res++;
            return;
        }
        grid[x][y] = -1;
        backtrack(grid, x+1, y, count+1);
        backtrack(grid, x-1, y, count+1);
        backtrack(grid, x, y+1, count+1);
        backtrack(grid, x, y-1, count+1);
        grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x, y;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
                else if(grid[i][j] == 0)
                    empty++;
            }
        }
        backtrack(grid, x,y, 0);
        return res;
    }
};
