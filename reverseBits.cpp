class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //approach 1
        // uint32_t rev = 0, power = 31;
        // while(n != 0){
        //     rev += (n&1)<<power;
        //     n = n>>1;
        //     power--;
        // }
        // return rev;
        
        //approach 2
        uint32_t m = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            m <<= 1;
            m |= n & 1;
        }
        return m;
    }
};
