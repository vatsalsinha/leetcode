class Solution {
public:
    void dfs(int i, unordered_map<int, unordered_set<int>>& al, vector<int>& quiet, vector<int>& visited,int& pos){
        if(visited[i]){            
            return;
        }
        if(quiet[pos] > quiet[i])
            pos = i;
        if(al.find(i) == al.end())
            return;
        visited[i] = 1;
        for(int e : al[i]){
            if(!visited[e]){
                dfs(e, al, quiet, visited, pos);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int, unordered_set<int>> al(n);
        for(int i = 0; i < richer.size(); i++){
            al[richer[i][1]].insert(richer[i][0]);
        }
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++){
            int pos = i;
            vector<int> visited(n);
            dfs(i, al, quiet, visited,pos);
            ans[i] = pos;
        }
        return ans;
    }
};
