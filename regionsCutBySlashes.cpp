class Solution {
public:
    void dfs(vector<vector<int>>& g, int i, int j){
        if(i < 0 || j < 0 || i >= g.size() || j >= g.size() || g[i][j] == 0)
            return;
        g[i][j] = 0;
        dfs(g, i-1, j);
        dfs(g, i+1, j);
        dfs(g, i, j-1);
        dfs(g, i, j+1);
    }
    int regionsBySlashes(vector<string>& grid) {
        //dfs solution
        //union find is a better approach. Will update solution soon
        vector<vector<int>> g(grid.size()*3, vector<int>(grid.size()*3, 1));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(grid[i][j] == '/'){ // making a forward slash
                    g[i*3][j*3+2] = 0;
                    g[i*3+1][j*3+1] = 0;
                    g[i*3+2][j*3] = 0;
                }
                else if(grid[i][j] == '\\'){ // making a backward slash
                    g[i*3][j*3] = 0;
                    g[i*3+1][j*3+1] = 0;
                    g[i*3+2][j*3+2] = 0;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < g.size(); i++){
            for(int j = 0; j < g.size(); j++){
                if(g[i][j] == 1){
                    dfs(g, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
