class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        int n = scores.size(), ans = 0;
        int dp[n];
        for(int i = 0; i < scores.size(); i++){
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++){
            dp[i] = v[i].second;
            ans = max(ans, dp[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = i-1; j > -1; j--){
                if(v[i].second >= v[j].second)
                    dp[i] = max(dp[i], v[i].second+dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
