class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 2 is the maximum number of MHTs a graph can have
        // this is so: 0-1-2-3-4-5
        //0 and 5 wont contribute to root
        // thus, 1-2-3-4
        //similarly, 1 and 4 wont contribute
        // thus 2-3. This is the max number, thus answer
        
        if(n == 1)
            return {0};
        vector<int> indegree(n,0);
        vector<vector<int>> graph(n);
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1)
                q.push(i);
        }
        while(n > 2){
            int sz = q.size();
            n -= sz;
            while(sz--){
                int node = q.front();
                q.pop();
                for(auto e : graph[node]){
                    indegree[e]--;
                    if(indegree[e] == 1){
                        q.push(e);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
