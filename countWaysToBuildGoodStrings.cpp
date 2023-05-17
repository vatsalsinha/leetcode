class Solution {
public:
//long long dp[10001];
//int mod = 1e9+7;
    // long long dfs(int length, int low, int high, int zero, int one){
    //     if(length > high)
    //         return 0;
    //     if(dp[length])
    //         return dp[length];
    //     // int res = length >= low ? 1 : 0;
    //     // res += dfs(length+zero, low, high, zero, one) + dfs(length+one, low, high, zero, one);
    //     long long sum = 0;
    //     sum =  length >= low ? 1 : 0;
    //     sum += dfs(length+zero, low, high, zero, one) + dfs(length+one, low, high, zero, one);
    //     return dp[length] = sum % mod;
    // }
    int countGoodStrings(int low, int high, int zero, int one) {
        // int length = 0;
        // return dfs(length, low, high, zero, one);

        //iterative DP:
        int mod = 1e9+7;
        int dp[high+1];
        memset(dp, 0, sizeof dp);
        int res = 0;
        dp[0] = 1;
        for(int i = 1; i < high+1; i++){
            // if we can add 0 string then add 
            if (i >= zero) dp[i] = (dp[i] + dp[i - zero]) % mod;
            // if we can add 1's string i.e i >= len of 1's string
            if (i >= one) dp[i] = (dp[i] + dp[i - one]) % mod;
            // if i is in between low and high add 
            if (i >= low) res = (res + dp[i]) % mod;
        }
        return res;
    }
};
/* 
Given we can append 0 zero number of times and 1 one number of times

so if zero is 4 then 0000 is considered one string and one is 3 then 111 is considered one string

now using these two strings we will have to make some new string that has a length between low and high inclusive

Now treat the length of final string to make as a target that needs to be achieved

and the length of strings from which the final string to be made as coin values

q] why will this work ?
we can at once append zero 0's or one 1's to string . and our final objective is to make a length of string
that lies in a range. ans is only dependent on one and zero.

Conclusion :-
So all we have to do is to run a for loop from low to high and call the function that will return total number of ways to make a string of that length . And that is similar to coin change problem

This top down approach will see all possible ways to get a score k
*/
