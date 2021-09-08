class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> r, c;
        for(int i=0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        sort(r.begin(), r.end());
        sort(c.begin(), c.end());
        int size = r.size()/2;
        int x = r[size];
        int y = c[size];
        int ans = 0;
        for(int i=0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]){
                    ans += abs(x-i) + abs(y-j);
                }
            }
        }
        return ans;
    }
};
