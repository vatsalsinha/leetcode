class Solution {
public:
    int visited[2001] = {0};
    bool checkCycle(vector<vector<int>>& g, int node){
        if(visited[node] == 1)
           return 1;
        if(!visited[node]){
            visited[node] = 1;
            for(int i = 0; i < g[node].size(); i++){
                if(checkCycle(g, g[node][i]))
                    return 1;
            }
        }
        visited[node] = 2;
        return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        for(auto v : prerequisites){
            g[v[1]].push_back(v[0]);
        }
        for(int i = 0; i < numCourses; i++)
            if(checkCycle(g, i))
                return 0;
        return 1;
    }
};
