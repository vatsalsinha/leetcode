class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int cmp = INT_MIN;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] < cmp)
                ans++;
            else
                cmp = intervals[i][1];
        }
        return ans;
    }
};
