class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, ans = 0;
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size()-1;
        while(low <= high && (power >= tokens[low] || score > 0)){
            //face up token
            while(low <= high && power >= tokens[low]){
                power -= tokens[low++];
                score++;
                }
            ans = max(score, ans);
            //face down token
            if(low <= high && score > 0){
                score--;
                power += tokens[high--];
            }
        }
        return ans;
    }
};

//sort the array
// If there is enough power to flip the token[l], then do it and get 1 point.
//if there is not enough power to flip token[l], then use 1 point to get the token[r] power.
//If can not do both, stop.
