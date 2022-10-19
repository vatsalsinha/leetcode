class Solution {
public:
     static bool cmp(pair<string, int>& a, pair<string, int>& b ){
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
    vector<pair<string, int>> sorta(unordered_map<string, int>& M){  
        vector<pair<string, int> > A;
        for (auto& it : M) {
            A.push_back(it);
        }
        sort(A.begin(), A.end(), cmp);
        return A;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto w : words)
            mp[w]++;
        vector<string> ans;
        auto g = sorta(mp);
        for(auto it = g.begin(); it != g.end() && k--; it++){
            ans.push_back(it->first);
        }
        return ans;
    }
};
