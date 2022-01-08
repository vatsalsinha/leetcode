class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c1, int c2, vector<vector<vector<int>>>& dp){
        if(r < 0 || r >= grid.size() || c1 < 0 || c1 >= grid[0].size() || c2 < 0 || c2 >= grid[0].size())
            return 0;
        if(dp[r][c1][c2])
            return dp[r][c1][c2];
        int maxCherries = 0;
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){
                int nc1 = c1 + i;
                int nc2 = c2+j;
                maxCherries = max(maxCherries, dfs(grid, r+1, nc1, nc2, dp));
            }
        }
        int currCherries = 0;
        if(c1 == c2){
            currCherries = grid[r][c1];
        }
        else{
            currCherries = grid[r][c1] + grid[r][c2];
        }
        dp[r][c1][c2] = currCherries + maxCherries;
        return dp[r][c1][c2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // row, col for rob1, col for rob2
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,0)));
        return dfs(grid, 0, 0, m-1, dp);
    }
};
