class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> v(candies.size());
        int m = *max_element(candies.begin(), candies.end());
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= m)
                v[i] = true;
            else
                v[i] = false;
        }
        return v;
    }
};
