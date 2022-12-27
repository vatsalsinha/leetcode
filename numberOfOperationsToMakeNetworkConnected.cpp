class Solution {
public:
    vector<int> visited;
    bool dfs(vector<vector<int>>&al, int i){
        if(visited[i])
            return false;
        visited[i] = true;
        for(auto n : al[i])
            dfs(al, n);
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> al(n);
        visited.resize(n, false);
        if(connections.size() < n-1)
            return -1;
        for(auto c : connections){
            al[c[0]].push_back(c[1]);
            al[c[1]].push_back(c[0]);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            count += dfs(al, i);
        }
        return count-1;
    }
};
