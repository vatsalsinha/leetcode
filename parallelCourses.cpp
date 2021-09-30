class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> inDegree(n+1, 0);
        vector<vector<int>> graph(n+1);
        for(auto r : relations){
            graph[r[0]].push_back(r[1]);
            inDegree[r[1]]++;
        }
        int semester = 0, subject = 0;
        queue<int> q;
        for(int i = 1; i < n+1; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        vector<int> sortedOrder;
        while(!q.empty()){
            semester++;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int src = q.front();
                q.pop();
                sortedOrder.push_back(src);
                for(auto node : graph[src]){
                    if(--inDegree[node] == 0)
                        q.push(node);
                }
            }
        }
        return sortedOrder.size() == n ? semester : -1;
    }
};
