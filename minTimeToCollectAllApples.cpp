class Solution {
public:
    int dfs(vector<vector<int>>& graph, vector<bool>& hasApple, int currNode, int parentNode){
        int time = 0, childTime = 0;
        for(auto child : graph[currNode]){
            if(child == parentNode)
                continue;
            childTime = dfs(graph, hasApple, child, currNode);
            if(childTime || hasApple[child])
                time += childTime + 2;
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        for(auto v : edges){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        return dfs(graph,hasApple, 0, -1);
    }
};
