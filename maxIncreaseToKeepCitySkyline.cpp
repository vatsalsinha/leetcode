class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> maxR(n, 0);
        vector<int> maxC(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                maxR[i] = max(maxR[i], grid[i][j]);
                maxC[j] = max(maxC[j], grid[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans += min(maxR[i], maxC[j]) - grid[i][j];
            }
        }
        return ans;
    }
};
