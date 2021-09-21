class Solution {
public:
    void dfs(string src, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string> &ans){
        auto &a = graph[src];
        while(!a.empty()){
            string s = a.top();
            a.pop();
            dfs(s, graph, ans);
        }
        ans.insert(ans.begin()+0, src);
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for(auto v : tickets){
            graph[v[0]].push(v[1]);
        }
        vector<string> ans;
        dfs("JFK", graph, ans);
        return ans;
    }
};
