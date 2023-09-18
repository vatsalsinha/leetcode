class Solution {
public:
    bool static cmp(pair<int, int>&a, pair<int, int>&b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> store(mat.size());
        for(int i = 0; i < mat.size(); i++){
            // int sum = 0;
            // for(int j = 0; j < mat[0].size(); j++){
            //     sum += mat[i][j];
            // }
            auto ind_itr = lower_bound(mat[i].begin(), mat[i].end(), 0, greater<int>());
            int ind = ind_itr - mat[i].begin();
            store[i] = {i, ind};
            cout<<i<<":"<<ind<<"\n";
        }
        sort(store.begin(), store.end(), cmp);
        vector<int> a;
        for(int i = 0; i < k; i++){
            a.push_back(store[i].first);
        }
        return a;
    }
};
