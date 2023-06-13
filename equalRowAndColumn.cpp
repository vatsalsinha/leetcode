class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            string sum1;
            for(int j = 0; j < n; j++){
                sum1 += to_string(grid[i][j])+"#";            }
            mp[sum1]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            string sum2;
            for(int j = 0; j < n; j++){
                sum2 += to_string(grid[j][i])+"#";
            }
            if(mp.find(sum2) != mp.end())
                ans += mp[sum2];
        }
        return ans;
    }
};
