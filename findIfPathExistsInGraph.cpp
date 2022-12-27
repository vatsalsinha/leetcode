class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> al(n);
        for(int i = 0; i < edges.size(); i++){
            al[edges[i][0]].push_back(edges[i][1]);
            al[edges[i][1]].push_back(edges[i][0]);
        }
        //bfs
        queue<int> q;
        q.push(start);
        vector<int> visited(n);
        visited[start] = 1;
        while(!q.empty()){
            int e = q.front();
            visited[e] = 1;
            if(e == end)
                return true;
            q.pop();
            for(auto i : al[e]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        return false;
    }
};
