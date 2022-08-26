class Solution {
public:
    //generate all powers of 2 and check whether N has number of same digits as in some power of 2
    vector<int> getSum(int n){
        vector<int> N(10, 0);
        while(n != 0){
            N[n%10]++;
            n /= 10;
        }
        return N;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> N = getSum(n);
        for(int i = 0; i < 31; i++){
            if(N == getSum(1 << i))
                return 1;
        }
        return 0;
    }
};
