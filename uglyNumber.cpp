class Solution {
public:
    int divide(int n, int f){
        while(n % f == 0)
            n /= f;
        return n;
    }
    bool isUgly(int n) {
        if(n <= 0)
            return 0;
        for(auto f : {2, 3, 5}){
            n = divide(n, f);
        }
        return n == 1;
        
    }
};
