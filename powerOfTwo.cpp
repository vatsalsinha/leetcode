class Solution {
public:
    bool isPowerOfTwo(int n) {
        // bit manipulation
        if(n <= 0)
            return 0;
        return !(n&(n-1));
        // math logic
        // if(n == 0)
        //     return 0;
        // if(n == 1)
        //     return 1;
        // return floor(log2(n)) == ceil(log2(n));
    }
};
