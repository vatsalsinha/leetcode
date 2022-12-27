class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> v(rocks.size());
        for(int i = 0; i < rocks.size(); i++){
            v[i] = capacity[i] - rocks[i];
        }
        sort(v.begin(), v.end());
        int count = 0;
        for(int i = 0; i < v.size(); i++){
            if(additionalRocks >= v[i]){
                additionalRocks -= v[i];
                count++;
            }
            else
                break;

        }
        return count;
    }
};
/*

1 1 0 1


*/
