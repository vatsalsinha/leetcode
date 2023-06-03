class Solution {
public:
// unordered_set<int> vis;
    void dfs(vector<vector<int>>& graph, int head, vector<int>& informTime, int time, int& ans){
        // vis.insert(head);
        time += informTime[head];
        ans = max(time, ans);
        for(auto e : graph[head]){
            // if(!vis.count(e))
                dfs(graph, e, informTime, time, ans);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
          vector<vector<int>> graph(n);
          for(int i = 0; i < n; i++){
              if(manager[i] == -1)
                continue;
              graph[manager[i]].push_back(i);
          }
          for(int i = 0; i < n; i++){
              for(int j = 0; j < graph[i].size(); j++){
                  cout<<i<<":"<<graph[i][j]<<endl;
              }
              cout<<endl;
          }
          int ans = INT_MIN;
          dfs(graph, headID, informTime, 0, ans);
          return ans;
    }
};
