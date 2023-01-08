class Solution {
public:
    double get_slope(vector<int> p1, vector<int> p2) {
        return atan2(p2[1] - p1[1], p2[0] - p1[0]);
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1)
            return 1;
        int count = 2;
        for(int i = 0; i < points.size()-1; i++){
            unordered_map<double, int> mp;
            for(int j = 0; j < points.size(); j++){
                if(i == j)
                    continue;
                double slope = get_slope(points[i], points[j]);
                mp[slope]++;
            }
            for(auto it : mp){
                count = max(count, it.second+1);
            }
        }
        return count;
    }
};
