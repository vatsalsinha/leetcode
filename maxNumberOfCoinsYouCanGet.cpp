class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int me = piles.size()-2;
        if(piles.size() == 3)
            return piles[me];
        int sum = 0;
        for(int i = 0; i < piles.size() / 3; i++){
            sum += piles[me];
            me -= 2;
            //i = n/3; i < n; i+=2
        }
        return sum;
    }
};
