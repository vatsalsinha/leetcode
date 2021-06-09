class Solution {
public:
    bool isSubsequence(string s, string t) {
        //approach 1 Queue
        // queue<char> q;
        // for(int i = 0; i < s.size(); i++){
        //     q.push(s[i]);
        // }
        // for(int i = 0; i < t.size(); i++){
        //     if(t[i] == q.front())
        //         q.pop();
        // }
        // return q.size() == 0;
        
        //approach 2 two pointers
        // int m = s.size();
        // int n = t.size();
        // int i = 0, j = 0;
        // while(i < m && j < n) {
        //     if(s[i] == t[j]) {
        //         i++;
        //     }
        //     j++;
        // }
        // return i == m ? 1 : 0;
        
        //approach 3 DP LCS way
        int dp[s.size()+1][t.size()+1];
        for(int i = 0; i < s.size()+1; i++){
            for(int j = 0; j < t.size()+1; j++){
                if(i == 0){
                    dp[i][j] = 0;
                }
                else if(j==0){
                    dp[i][j] = 0;
                }
                else{
                    if(s[i-1] == t[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};
