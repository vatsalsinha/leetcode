class Solution {
public:
    // //recursive approach
    // int dfs(vector<vector<int>> questions, vector<long long>& dp, int i){
    //     if(i >= questions.size())
    //         return 0;
    //     if(dp[i])
    //         return dp[i];
    //     dp[i] = max(questions[i][0] + dfs(questions, dp, i+questions[i][1]+1), dfs(questions, dp, i+1));
    //     return dp[i];
    // }
    long long mostPoints(vector<vector<int>>& questions) {
        // vector<long long> dp(questions.size(),0);
        // return dfs(questions, dp, 0);

        // Iterative approach
        int n = questions.size();
        long long dp[n];
        dp[n-1] = questions[n-1][0];
        for(int i = n-2; i >= 0; i--){
            dp[i] = questions[i][0];
            if(i+1+questions[i][1] < n)
                dp[i] += dp[i+questions[i][1]+1];
            dp[i] = max(dp[i], dp[i+1]);
        }
        return dp[0];
    }
};
