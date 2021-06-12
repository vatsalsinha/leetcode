class Solution {
public:
    // vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    // void backtrack(int n, char last, int& count){
    //     if(n == 0)
    //         count++;
    //     else{
    //         for(auto e : vowels){
    //             if(last <= e)
    //                 backtrack(n-1, e, count);
    //         }
    //     }
    // }
    int countVowelStrings(int n) {
        vector<int> dp(5, 1);
        for(int i = 0; i < n; i++){
            for(int j = 1; j < 5; j++){
                dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[4];
        // int count = 0;
        // backtrack(n, ' ', count);
        // return count;
    }
};
