class Solution {
public:
    int candy(vector<int>& ratings) {
        /* approach 1
        vector<int> lr(ratings.size(),1), rl(ratings.size(),1);
        for(int i = 0; i < ratings.size()-1; i++){
            if(ratings[i+1] > ratings[i])
                lr[i+1] = lr[i]+1;
        }
        int sum = 0;
        for(int i = ratings.size()-1; i > 0; i--){
            if(ratings[i-1] > ratings[i])
                rl[i-1] = rl[i]+1;
        }
        for(int i = 0; i < ratings.size(); i++)
            sum += max(lr[i], rl[i]);
        return sum;
        */
        vector<int> candies(ratings.size(),1);
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        int sum = candies[ratings.size()-1];
        for(int i = candies.size()-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1]+1);
            sum += candies[i];
        }
        return sum;
    }
};
