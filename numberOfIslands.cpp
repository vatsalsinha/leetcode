class Solution {
public:
    void mark(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j >= grid[0].size() || j < 0 || grid[i][j] != '1')
            return;
        grid[i][j] = '2'; //visited
        mark(grid, i-1, j);
        mark(grid, i+1, j);
        mark(grid, i, j-1);
        mark(grid, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    mark(grid, i, j);
                    n++;
                }
            }
        }
        return n;
    }
};
