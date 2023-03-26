class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> indegree(n);
        vector<bool> vis(n);
        //kahn's algorithm for topological sort
        for(int i = 0; i < n; i++){
            if(edges[i] != -1)
                indegree[edges[i]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int neighbor = edges[node];
            vis[node] = 1;
            if(neighbor != -1){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        //-------------
        int ans = -1;
        for(int i = 0; i < n; i++){
            //calculating length of cycle
            if(!vis[i]){
                int count = 1;
                int neighbor = edges[i];
                vis[i] = 1;
                while(neighbor != i){
                    vis[neighbor] = 1;
                    count++;
                    neighbor = edges[neighbor];
                }
                ans = max(count, ans);
            }
        }
        return ans;
    }
};
