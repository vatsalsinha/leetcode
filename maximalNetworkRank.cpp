class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxi = 0;
        vector<unordered_set<int>> al(n);
        for(int i = 0; i< roads.size(); i++){
            al[roads[i][0]].insert(roads[i][1]);
            al[roads[i][1]].insert(roads[i][0]);
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int tmp = al[i].size() + al[j].size();
                if(al[j].count(i))
                    tmp--;
                maxi = max(tmp, maxi);
            }
        }
        return maxi;
    }
};
