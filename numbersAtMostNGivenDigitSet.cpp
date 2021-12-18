class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
	// a lot of help from leetcode solution
        //DP
        string S = to_string(n);
        int K = S.size();
        int dp[K+1];
        memset(dp, 0, sizeof dp);
        dp[K] = 1;
        for(int i = K-1; i > -1; i--){
            int Si = S[i]-'0';
            for(auto d : digits){
                if(stoi(d) < Si)
                    dp[i] += pow(digits.size(), K-i-1);
                else if(stoi(d) == Si)
                    dp[i] += dp[i+1];
            }
        }
        for(int i = 1; i < K; i++)
            dp[0] += pow(digits.size(), i);
        return dp[0];
        
        //MATH approach
        // int B = digits.size();
        // string N = to_string(n);
        // int K = N.size();
        // int A[K];
        // int t = 0;
        // for(auto c : N){
        //     int c_index = 0;
        //     bool match = 0;
        //     for(int i = 0; i < B; i++){
        //         if(c >= digits[i][0])
        //             c_index = i+1;
        //         if(c == digits[i][0])
        //             match = true;
        //     }
        //     A[t++] = c_index;
        //     if(match)
        //         continue;
        //     if(c_index == 0){
        //         for(int j = t-1; j > 0; j--){
        //             if(A[j])
        //                 break;
        //             A[j] += B;
        //             A[j-1]--;
        //         }
        //     }
        //     while(t < K)
        //         A[t++] = B;
        //     break;
        // }
        // int ans = 0;
        // for(int i = 0; i < K; i++){
        //     ans = ans*B + A[i];
        // }
        // return ans;
    }
};
