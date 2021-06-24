class Solution {
public:
    int mod = pow(10,9)+7;
    int helper(int m, int n, int maxMove, int i, int j, int moves, vector<vector<vector<int>>>& dp){
        if(i >= m || i < 0 || j >=n || j < 0)
            return 1;
        if(maxMove == moves)
            return 0;
        if(dp[moves][i][j] != -1)
            return dp[moves][i][j] % mod;
        int temp = 0;
        temp = (temp + helper(m,n,maxMove,i+1,j,moves+1,dp)) % mod;
        temp = (temp + helper(m,n,maxMove,i-1,j,moves+1,dp)) % mod;
        temp = (temp + helper(m,n,maxMove,i,j+1,moves+1,dp)) % mod;
        temp = (temp + helper(m,n,maxMove,i,j-1,moves+1,dp)) % mod;
        dp[moves][i][j] = temp;
        return dp[moves][i][j] % mod; 
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        
        dp[maxMove][m][n] = helper(m,n,maxMove,startRow,startColumn,0,dp);
        return dp[maxMove][m][n];
        
    }
};
