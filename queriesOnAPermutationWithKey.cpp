class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans, p;
        for(int i = 0; i < m; i++){
            p.push_back(i+1);
        }
        for(int i = 0; i < queries.size(); i++){
            auto it = find(p.begin(), p.end(), queries[i]);
            int index = it - p.begin();
            ans.push_back(index);
            p.erase(it);
            p.insert(p.begin(), queries[i]);
        }
        return ans;
    }
};
