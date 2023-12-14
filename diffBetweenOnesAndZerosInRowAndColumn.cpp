class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> rs(grid.size()), cs(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j])
                    rs[i]++, cs[j]++;
            }
        }
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans[i][j] = 2*rs[i] + 2*cs[j] - grid.size() - grid[0].size();
            }
        }
        return ans;
    }
};
// r + c - [(m-r) + (n-c)]
// 2r + 2c - m -n
