class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto a : accounts){
            int sum = 0;
            for(auto b : a){
                sum += b;
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
