class Solution {
public:
    int gcd(int x, int y){
        return x == 0 ? y : gcd(y%x, x);
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> fractions;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(gcd(i, j) == 1){
                    fractions.push_back(to_string(j) + '/' + to_string(i));
                }
            }
        }
        return fractions;
    }
};
