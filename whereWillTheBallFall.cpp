class Solution {
public:
    bool isValid(int R, int C, int r, int c){
        if(r >= R || r < 0 || c >= C || c < 0)
            return false;
        return true;
    }
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r == grid.size())
            return c;
        if(isValid(grid.size(), grid[0].size(), r, c)){
            if(grid[r][c] == 1){
                if(isValid(grid.size(), grid[0].size(), r, c+1) && grid[r][c+1] == 1)
                    return dfs(grid, r+1, c+1);
            }
            else{
                if(isValid(grid.size(), grid[0].size(), r, c-1) && grid[r][c-1] == -1)
                    return dfs(grid, r+1, c-1);
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int col = grid[0].size();
        vector<int> ans(col,0);
        for(int c = 0; c < col; c++)
            ans[c] = dfs(grid, 0, c);
        return ans;
    }
};
