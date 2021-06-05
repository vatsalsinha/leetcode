class Solution {
public:
    int numberOfSteps(int num) {
        // int steps = 0;
        // while(num != 0){
        //     if(num % 2 == 0)
        //         num = num / 2;
        //     else
        //         num -= 1;
        //     steps++;
        // }
        // return steps;
        
        /* bit manipulation
        int __builtin_popcount(unsigned int x): Returns the number of 1-bits in x.
        int __builtin_clz(unsigned int x): Returns the number of leading 0-bits in x, starting at the most significant bit          position. If x is 0, the result is undefined. The reason for adding 31 and not 32 is because we don't have to shift the last zero.
        */
        return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
    }
};
