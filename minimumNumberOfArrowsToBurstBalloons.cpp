class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // better logic
        int ans = 0, minEnd = INT_MAX;
        sort(points.begin(), points.end());
        for(auto p : points){
            if(p[0] > minEnd){
                ans++; // arrow shot
                minEnd = p[1]; // updating for the next set of balloons
            }
            else{
                minEnd = min(p[1], minEnd); // merging 
            }
        }
        return ans + !points.empty();
        // mergeInterval logic 
        //Takes extra space
        // sort(points.begin(), points.end());
        // vector<vector<int>> vec;
        // for(auto v : points){
        //     if(vec.empty() || vec.back()[1] < v[0])
        //         vec.push_back(v);
        //     else if(vec.back()[1] >= v[0]){
        //         vec.back()[1] = min(vec.back()[1], v[1]); // merging happens
        //     }
        // }
        // return vec.size();
    }
};

/* 
    1 6
    2 8
    7 12
    10 16
*/
