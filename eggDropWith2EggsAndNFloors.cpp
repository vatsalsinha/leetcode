class Solution {
public:
    int twoEggDrop(int n) {
        int dp[3][n+1]; // dp[eggs+1][floors+1]
        for(int i = 1; i < 3; i++){ // eggs
            for(int j = 1; j < n+1; j++){ //floors
                if(i == 1){
                    dp[i][j] = j;
                }
                else if(j == 1){
                    dp[i][j] = 1;
                }
                else{
                    int m = INT_MAX;
                    for(int mj = j-1, pj = 0; mj >= 0; mj--, pj++){
                        int v = max(dp[i-1][pj], dp[i][mj]); //dp[i-1][pj] -> egg breaks; dp[i][mj] ->egg survives
                        m = min(v, m);
                    }
                    dp[i][j] = m+1;
                }
            }
        }
        return dp[2][n];
    }
};
