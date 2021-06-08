class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dX = coordinates[1][0] - coordinates[0][0];
        int dY = coordinates[1][1] - coordinates[0][1];
        for(auto v : coordinates){
            if(dX*(v[1] - coordinates[0][1]) != dY*(v[0] - coordinates[0][0]))
                return false;
        }
        return true;
    }
};
