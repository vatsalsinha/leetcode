class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0 ){
            return res;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tmp = intervals[0];
        for(auto it : intervals){
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
