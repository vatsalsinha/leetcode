class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // sort(costs.begin(), costs.end());
        // int score = 0;
        // for(int i = 0; i < costs.size(); i++){
        //     if(coins >= costs[i]){
        //         score++;
        //         coins -= costs[i];
        //     }
        // }
        // return score;
        sort(costs.begin(), costs.end());
        for(int i = 0; i < costs.size(); i++){
            if((coins -= costs[i]) < 0)
                return i;
        }
        return costs.size();
    }
};
