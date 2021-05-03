class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==1){
            return s;
        }
        bool dp[s.length()][s.length()];
        memset(dp, 0, sizeof(dp));
        string result = "";
        for(int g = 0; g < s.length(); g++){
            for(int i = 0, j = g; j < s.length(); i++,j++){
                if(g == 0){
                    dp[i][j] = true;
                }
                else if(g ==1){
                    if(s[i] == s[j]){
                            dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                if(dp[i][j])
                    result = s.substr(i, j-i+1);
            }
        }
        return result;
    }
};

