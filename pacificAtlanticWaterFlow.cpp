class Solution {
public:
    // idea is to start from pacific and see what can go to pacific 
    //then start from atlantic and see what can got to atlantic
    // points which can go to both are part of answers
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& visited, int prevHeight){
        if(r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || heights[r][c] < prevHeight || visited[r][c])
            return;
        visited[r][c] = 1;
        dfs(r+1, c, heights, visited, heights[r][c]);
        dfs(r-1, c, heights, visited, heights[r][c]);
        dfs(r, c+1, heights, visited, heights[r][c]);
        dfs(r, c-1, heights, visited, heights[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pac(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> atl(heights.size(), vector<int>(heights[0].size(), 0));
        vector<vector<int>> res;
        for(int i = 0; i < heights.size(); i++){
            dfs(i, 0, heights, pac, 0);
            dfs(i, heights[0].size()-1, heights, atl, 0);
        }
        for(int i = 0; i < heights[0].size(); i++){
            dfs(0, i, heights, pac, 0);
            dfs(heights.size()-1, i, heights, atl, 0);
        }
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(pac[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};
