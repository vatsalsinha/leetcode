class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1){
            return x;
        }
        if(n == 0){
            return 1;
        }
        if(n < 0){
            x = 1/x;
        }
        double val = myPow(x, abs(n)/2);
        // odd even case 
        return n%2 ? val*val*x : val*val;
        
    }
};
