class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int& islandId){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
            return 0;
        grid[i][j] = islandId;
        return 1 + dfs(grid, i+1, j, islandId) + dfs(grid, i-1, j, islandId) + dfs(grid, i, j+1, islandId) + dfs(grid, i, j-1, islandId);
        
    }
    int largestIsland(vector<vector<int>>& grid) {
        int maxArea = INT_MIN;
        vector<vector<int>> directions{{1, 0}, {-1, 0},{0, 1},{0, -1}};
        int m = grid.size();
        int n = grid[0].size();
        int islandId = 2; // since 1 is already being used
        unordered_map<int, int> dict; // islandId : size
        //get maxarea of island without modification
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int size = dfs(grid, i, j, islandId);
                    maxArea = max(maxArea, size);
                    dict[islandId++] = size;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    for(auto direction : directions){
                        int x = i + direction[0];
                        int y = j + direction[1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0)
                            st.insert(grid[x][y]);
                    }
                    int sum = 1; // already changed 0 to 1
                    for(auto s : st){
                        sum += dict[s];
                    }
                    maxArea = max(maxArea, sum);
                }
            }
        }
        return maxArea;
    }
};
