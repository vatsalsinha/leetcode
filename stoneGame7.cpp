class Solution {
public:
    int memo(vector<vector<int>> & dp, vector<int>& stones, int sum, int start, int end){
        if(sum <= 0) return 0; 
        if(start== end )return 0;
        if(dp[start][end]!= -1)return dp[start][end]; 
        
        int res = max(sum-stones[start]- memo(dp,stones, sum-stones[start], start+1, end),
                      sum-stones[end]- memo(dp,stones, sum-stones[end], start, end-1)
                     );
        dp[start][end ] = res ;
        return dp[start][end];
    }
    int stoneGameVII(vector<int>& stones) {
        //Dynamic Programming
        // int N =  stones.size();
        // vector<int> sum(N+1,0);
        // for(int i = 0; i < N; i++)
        //     sum[i+1] = sum[i] + stones[i];
        // vector<vector<int>> dp(N, vector<int>(N));
        // for(int len = 2; len < N+1; len++){
        //     for(int i = 0; i < N - len + 1; i++){
        //         int j = i+len-1;
        //         dp[i][j] = max(sum[j+1] - sum[i+1]-dp[i+1][j], sum[j]-sum[i]-dp[i][j-1]);
        //     }
        // }
        // return dp[0][N-1];
        
        //DP with dfs
        int sum = 0 ;
        int n = stones.size(); 
        for(auto x:stones) sum +=x;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1)); 
        return memo(dp , stones, sum, 0, n-1) ;
    }
};
