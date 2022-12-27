class Solution {
public:
    void dfs(string s, string d, unordered_map<string, vector<pair<string, double>>>& m, unordered_set<string> v, double& ans, double tmp){
        if(v.count(s) > 0)
            return;
        v.insert(s);
        if(s == d){
            ans = tmp;
            return;
        }
        else{
            for(auto a : m[s]){
                dfs(a.first, d, m, v, ans, tmp*a.second);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> m;
        for(int i = 0; i < equations.size(); i++){
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        vector<double> res;
        for(int i = 0; i < queries.size(); i++){
            string s = queries[i][0];
            string d = queries[i][1];
            double ans = -1.0;
            unordered_set<string> visited;
            if(m.count(s) > 0 && m.count(d) > 0)
                dfs(s, d, m, visited, ans, 1.0);
            res.push_back(ans);
        }
        return res;
    }
};
