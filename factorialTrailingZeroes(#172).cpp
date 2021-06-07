class Solution {
public:
    //  fact(int n){
    //     if(n < 2)
    //         return 1;
    //     return n*fact(n-1);
    // } can cause integer overflow
    int trailingZeroes(int n) {
        int count = 0;
        for(int i = 5; n/i >= 1; i*=5){
            count += n/i;
        }
        return count;
    }
};
