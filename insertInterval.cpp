class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<int> tmp = intervals[0];
        for( auto it : intervals){
            if(it[0] <= tmp[1]){
                tmp[1] = max(it[1], tmp[1]);
            }
            else{
                res.push_back(tmp);
                tmp = it;
            }
        }
        res.push_back(tmp);
        return res;
    }
};
