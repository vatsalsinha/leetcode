class Solution {
public:
    int dp[601][101][101];
    int helper(vector<pair<int, int>>& vec, int index, int m, int n){
        if(index == vec.size() || (m == 0 && n == 0))
            return 0;
        if(dp[index][m][n] != -1)
            return dp[index][m][n];
        if(vec[index].second > n || vec[index].first > m)
            return dp[index][m][n] = helper(vec, index+1, m, n);
        int include = 1 + helper(vec, index+1, m-vec[index].first, n-vec[index].second);
        int exclude = helper(vec, index+1, m, n);
        return dp[index][m][n] = max(include, exclude);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> vec;
        memset(dp, -1, sizeof dp);
        for(auto str : strs){
            int one = 0, zero = 0;
            for(auto j : str){
                if(j == '0')
                    zero++;
                else
                    one++;
            }
            vec.push_back({zero, one});
        }
        return helper(vec, 0, m, n);
    }
};
