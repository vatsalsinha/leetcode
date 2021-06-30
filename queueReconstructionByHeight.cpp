class Solution {
public:
    bool static cmp(vector<int>p1, vector<int> p2){
        return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); // sort in decreasing order by height. if height is same then sort by k in ascending order
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), cmp);
        for(auto v : people){
            res.insert(res.begin()+v[1], v);
        }
        return res;
    }
};
