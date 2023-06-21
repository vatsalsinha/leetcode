class Solution {
public:
//weighted median
    long long getCost(vector<int>& nums, vector<int>& cost, long long median){
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = ans + abs(1ll*nums[i]-median)*1ll*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>> v;
        long long sum = 0, median = 0;
        for(int i = 0; i < nums.size(); i++){
            v.push_back({nums[i], cost[i]});
            sum += cost[i];
        }
        sort(v.begin(), v.end());
        long long total = 0;
        int i = 0;
        while(total < (sum+1)/2 && i < nums.size()){
            total = total + 1ll * v[i].second;
            median = v[i].first;
            i++;
        }
        return getCost(nums, cost, median);

    }
};
