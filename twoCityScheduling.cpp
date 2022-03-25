class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>&b){
        return (a[0]-a[1]) < (b[0] - b[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp /*[](vector<int>&a, vector<int>&b){return (a[0]-a[1]) < (b[0] - b[1]); } */);
        int ans = 0;
        for(int i = 0; i < costs.size(); i++){
            if(i < costs.size()/2) // city A
                ans += costs[i][0];
            else    // city B
                ans += costs[i][1];
        }
        return ans;
    }
};
