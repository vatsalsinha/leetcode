class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD=1e9+7;
        //treat it as a graph. draw edges as per the rules. 
        long a = 1;
        long e = 1;
        long i = 1;
        long o = 1;
        long u = 1;
        for(int j = 2; j < n+1; j++){
            long A = (e + u + i) % MOD;
            long E = (a + i) % MOD;
            long I = (e + o) % MOD;
            long O = i % MOD;
            long U = (i+o) % MOD;
            a = A;
            e = E;
            i = I;
            o = O;
            u = U;
        }
        return (a+e+i+o+u) % MOD;
    }
};