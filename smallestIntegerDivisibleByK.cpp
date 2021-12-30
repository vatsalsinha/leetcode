class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 0;
        for(int i = 1; i < k+1; i++){
            rem = (rem*10 + 1) % k; // to prevent overflow
            if(rem == 0)
                return i;
        }
        return -1;
        /* 
            With N being an integer only composed of 1s, we are trying find the smallest N divisible by K. for length in range(1, K + 1) represents the number of digits in N that we are trying. If at any point N % K == 0, then we return N.

Otherwise, we stop at K digits because we haven't found the remainder 0. There are certain mathematical properties that come into play now:

There are K values for remainders, because we took N % K for K different Ns. There are normally K different values for remainders (0 to K-1). However exiting the for loop means we never got the remainder 0, so we only have K-1 possible values for remainders.
By the Pigeonhole Principle, when K pigeons (remainders) are placed into K-1 buckets (possible values for remainders), two pigeons (remainders) will be placed into the same bucket (values). Meaning at least two remainders will have the same value.
The remainders resulting from repeatedly taking the mod between a series and a K comprise a pattern. Our series is [int('1'*i) for i in [1,2,3...]]. Exiting the for loop at K+1, means we never encountered the remainder 0, and the remainders have repeated already, meaning the pattern has completed and it will never contain 0. So it is safe to stop and say there is no N divisible by K.
        https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/260875/Python-O(K)-with-Detailed-Explanations
        */
    }
};