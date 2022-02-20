class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b){
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0, maxTill = intervals[0][1];
        for(auto i = 1; i < intervals.size(); i++){
            if(intervals[i][1] <= maxTill)
                ans++;
            else
                maxTill = intervals[i][1];
        }
        return intervals.size()-ans;
    }
};
/*
1 4 a 
3 6 b
2 8 c

if(a[0] > b[0] && a[1] < b[1])
    del a




*/
