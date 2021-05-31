class Solution {
public:
    bool static compare(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        vector<int> ans;
        unordered_map<int, int> m;
        for(auto n : nums){
            m[n]++;
        };
        for(auto i : m){
            v.push_back({i.first, i.second});
        }
        sort(v.begin(), v.end(), compare);
        for(int i = 0; i < k; i++){
            ans.push_back(v[i].first);
        }
        return ans;
        // int n = nums.size();
        // vector<vector<int>> buckets(n + 1);
        // vector<int> ans;
        // unordered_map<int, int> counter;
        // for (int num : nums) {
        //     counter[num]++;
        // }
        // for (auto p : counter) {
        //     buckets[p.second].push_back(p.first);
        // }
        // for (int i = n; i >= 0 && ans.size() < k; i--) {
        //     if (!buckets[i].empty()) {
        //         ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        //     }
        // }
        // return ans;
    }
};
