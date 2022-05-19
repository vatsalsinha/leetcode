class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //Kahn's algorithm for topological sort
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(auto x : dir){
                    int nx = i + x[0];
                    int ny = j + x[1];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                        if(matrix[nx][ny] > matrix[i][j])
                            indegree[i][j]++;
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(indegree[i][j] == 0)
                    q.push({i,j});
            }
        }
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto t = q.front();
                q.pop();
                for(auto x : dir){
                    int nx = t.first + x[0];
                    int ny = t.second + x[1];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] < matrix[t.first][t.second]){
                        if(--indegree[nx][ny] == 0)
                            q.push({nx, ny});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
