class Solution {
public:
    int arrangeCoins(int n) {
        // BRUTE FORCE
        // if(n==1)
        //     return 1;
        // int count = 0;
        // for(int i = 1; i <= n; i++){
        //     n = n-i;
        //     if(n >= 0)
        //         count++;
        //     else
        //         break;
        // }
        // return count;
        /*  BINARY SEARCH
        This question is easy in a sense that one could run an exhaustive iteration to obtain the result. That could work, except that it would run out of time when the input becomes too large. So let us take a step back to look at the problem, before rushing to the implementation.

Assume that the answer is kk, i.e. we've managed to complete kk rows of coins. These completed rows contain in total 1 + 2 + ... + k = \frac{k (k + 1)}{2}1+2+...+k= k(k+1)/2 coins.

We could now reformulate the problem as follows:

Find the maximum k such that k(k+1)/2 <= N

The problem seems to be one of those search problems
        */
        long left = 0, right = n;
        long k, curr;
        while(left <= right){
            k = left + (right-left)/2;
            curr = k*(k+1)/2;
            if(curr == n)
                return (int)k;
            if(n < curr){
                right = k-1;
            }
            else
                left = k+1;
        }
        return (int)right;
    }
};