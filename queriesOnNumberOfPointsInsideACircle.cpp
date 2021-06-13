class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        for(int j = 0; j < queries.size(); j++){
            int count = 0;
            for(int i = 0; i < points.size(); i++){
                int xdiff = queries[j][0] - points[i][0];
                int ydiff = queries[j][1] - points[i][1];
                int dist = xdiff*xdiff + ydiff*ydiff;
                if(dist <= queries[j][2]*queries[j][2])
                    count++;
            }
            ans[j] = count;
        }
        return ans;
    }
};
