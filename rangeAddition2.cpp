class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0)
            return m*n;
        int r = INT_MAX, c = INT_MAX;
        for(auto v : ops){
            r = min(v[0], r);
            c = min(v[1], c);
        }
        return r * c;
    }
};
