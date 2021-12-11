class Solution {
public:
    long long gcd(int a, int b){
        if(b == 0)
            return a;
        return gcd(b, a%b);
    }
    int mod = 1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long long start = 0;
        long long end = LLONG_MAX;
        auto lcm = (a*b)/gcd(a,b);
        while(start < end){
            long long mid = (start+end)/2;
            long long target = (mid/a) + (mid/b) - (mid/lcm); // div by A + div by B - div by both
            if(target < n)
                start = mid+1;
            else
                end = mid;
        }
        return end%mod;
    }
};
