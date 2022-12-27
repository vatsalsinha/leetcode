class Solution {
public:
    int dfs(vector<vector<int>>& adjacencyList, int start, vector<bool>& visited){
        visited[start] = true;
        int count = 0;
        for(auto i : adjacencyList[start]){
            if(!visited[abs(i)])
                count += dfs(adjacencyList, abs(i), visited) + (i > 0);
        }
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjacencyList(n);
        for(auto& c : connections){
            adjacencyList[c[0]].push_back(c[1]);
            adjacencyList[c[1]].push_back(-c[0]);
        }
        vector<bool> visited(n);
        return dfs(adjacencyList, 0, visited);
    }
};
