class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> tables;
        set<string> food;
        for(auto v : orders){
            food.insert(v[2]);
            tables[stoi(v[1])][v[2]]++;
        }
        vector<vector<string>> res;
        vector<string> h(food.begin(),food.end());
        h.insert(h.begin(), "Table");
        res.push_back(h);
        for(auto it : tables){
            vector<string> r;
            r.push_back(to_string(it.first));
            for(auto f : food){
                r.push_back(to_string(it.second[f]));
            }
            res.push_back(r);
        }
        return res;
    }
};
