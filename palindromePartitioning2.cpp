class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> pal(n+1, vector<bool>(n+1));
        vector<int> dp(n+1);
        for(int i = 0; i <= n; i++) dp[i] = i - 1;
        for(int i = 2; i <= n; i++){
         for(int j = i - 1; j >= 0; j--){
             //if(isPalindr[j][i]){
             if(s[i - 1] == s[j] && (i - 1 - j < 2 || pal[j + 1][i - 1])){
                 pal[j][i] = true;
                 dp[i] = min(dp[i], dp[j] + 1);
             }
         }
     }
     
     return dp[n];
    }
};
