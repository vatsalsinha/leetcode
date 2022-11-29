class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        for(auto v : matches){
            mp[v[1]]++;
        }
        vector<vector<int>> ans;
        vector<int> win, los;
        for(auto v : matches){
            if(mp.find(v[0]) == mp.end()){
                win.push_back(v[0]);
                mp[v[0]] = -1;
            }
        }
        for(auto it : mp)
            if(it.second == 1)
                los.push_back(it.first);
        sort(win.begin(), win.end());
        sort(los.begin(), los.end());
        ans.push_back(win);
        ans.push_back(los);
        return ans;
    }
};
