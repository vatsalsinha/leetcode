class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
         if(dividend/divisor > INT_MAX || dividend/divisor < INT_MIN){
            return INT_MAX;
        }
        if(dividend == 0){
            return 0;
        }
        return dividend/divisor;
    }
};

