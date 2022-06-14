class Solution {
public:
    int minDistance(string text1, string text2) {
        //variation of LCS.
        int dp[text1.size()+1][text2.size()+1];
        for(int i = 0; i <= text1.size(); i++){
            for(int j = 0; j <= text2.size(); j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return text1.size() + text2.size() - 2 * dp[text1.size()][text2.size()]; // get no. of characters which are not common in both words
    }
};
