class Solution {
public:
    /* DFS:
    const int MAX = 10000;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j])
                    matrix[i][j] = MAX;
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j])
                    dfs(matrix, i, j);
        return matrix;
    }
    
    int dfs(vector<vector<int>>& matrix, int r, int c)
    {
        if(r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size() || matrix[r][c] == -1)
            return MAX;
        
        if(matrix[r][c] == 0 || matrix[r][c] == 1)
            return matrix[r][c];
        
        int temp = matrix[r][c];
        
        matrix[r][c] = -1;
        
        int left = dfs(matrix, r, c-1);
        int right = dfs(matrix, r, c+1);
        int down = dfs(matrix, r-1, c);
        int up = dfs(matrix, r+1, c);
        
        matrix[r][c] = min({temp, left + 1, right + 1, down + 1, up + 1});
        return matrix[r][c];
    }
    */
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX - 100000));

    //First pass: check for left and top
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0)
                dist[i][j] = 0;
            else {
                if (i > 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                if (j > 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }

    //Second pass: check for bottom and right
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (i < rows - 1)
                dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            if (j < cols - 1)
                dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
        }
    }

    return dist;
    }
};

// BFS
/*class Solution {
public:
    struct cell{
        int r, c, d;
    };
    cell createCell(int row, int col, int dist){
        cell a;
        a.r = row;
        a.c = col;
        a.d = dist;
        return a;
    }
    bool isValid(cell a, int n, int m){
        return a.r >= 0 && a.r < n && a.c >= 0 && a.c < m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); int m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        queue<cell> q;
        vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = 1;
                    ans[i][j] = 0;
                    q.push(createCell(i, j, 0));
                }
            }
        }
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto dir : directions){
                    cell adj = createCell(x.r + dir[0], x.c + dir[1], x.d+1);
                    if(isValid(adj,n,m) && !visited[adj.r][adj.c]){
                        visited[adj.r][adj.c] = 1;
                        if(ans[adj.r][adj.c] > ans[x.r][x.c] + 1){
                            ans[adj.r][adj.c] = ans[x.r][x.c] + 1;
                            q.push(adj);
                        }
                    }
                }
        }
        return ans;
    }
};
*/