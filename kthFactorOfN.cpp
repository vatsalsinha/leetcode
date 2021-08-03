class Solution {
public:
    int kthFactor(int n, int k) {
        //O(n)
        // //vector<int> factors;
        // for(int i = 1; i <= n/2; i++){
        //     if(n % i == 0)
        //         //factors.push_back(i);
        //         k--;
        //     if(k == 0)
        //         return i;
        // }
        // //factors.push_back(n);
        // //return factors.size() >= k ? factors[k-1] : -1;
        // return k-1 == 0 ? n : -1;
        
        //O(sqrt(n))
        for(int i = 1; i < sqrt(n); i++){ //divisors smaller than the square root of n
            if(n%i == 0 && --k == 0)
                return i;
        }   
        for(int i = (int)sqrt(n); i > 0; i--){ // divisors bigger than the square root of n.
            if(n % (n/i) == 0 && --k == 0)
                return n/i;
        }
        return -1;
    }
};