class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1)
            return true;
        if(n == 0)
            return false;
        double x = log(n)/log(4);
        cout<<x;
        return floor(x) == x;
        //return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};
