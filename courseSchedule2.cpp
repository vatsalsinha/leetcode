class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(numCourses);
        for(auto e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        vector<int> inDegree(numCourses);
        for(int i = 0; i < adj.size(); i++){
            for(int j = 0; j < adj[i].size(); j++){
                inDegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto e : adj[x]){
                inDegree[e]--;
                if(inDegree[e] == 0){
                    q.push(e);
                }
            }
        }
        if(ans.size() != numCourses)
            ans.clear();
        return ans;
    }
};
