class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> dict;
        for(int i = 0; i < logs.size(); i++){
            dict[logs[i][0]].insert(logs[i][1]);
        }
        vector<int> ans(k);
        /*
            0 : {5,2}, [size = 2]
            1 : {2,3} [size = 2]
        */
        for(auto it : dict)
            ans[it.second.size()-1]++;
        return ans;
    
    }
};
