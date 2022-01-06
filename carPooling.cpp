class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int stops[1001];
        memset(stops, 0, sizeof stops);
        for(auto trip : trips){
            stops[trip[1]] += trip[0];
            stops[trip[2]] -= trip[0];
        }
        for(int i = 0; i < 1001 && capacity >= 0; i++){
            capacity -= stops[i];
        }
        return capacity >= 0;
    }
};
