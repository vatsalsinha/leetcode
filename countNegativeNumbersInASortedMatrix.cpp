class Solution {
public:
    //approach 2
    // int bs(vector<int>& v){
    //     int l = 0, h = v.size();
    //     while(l < h){
    //         int mid = (l+h)/2;
    //         if(v[mid] >= 0)
    //             l++;
    //         else
    //             h=mid;
    //     }
    //     return l;
    // }
    int countNegatives(vector<vector<int>>& grid) {
        //approach 1
        // int count = 0;
        // for(auto v : grid)
        //     for(auto n : v)
        //         if(n < 0)
        //             count++;
        // return count;
        //approach 2
        // int count = 0;
        // for(auto v : grid){
        //     count += v.size()-bs(v);
        // }
        // return count;

        //aproach 3
        int count = 0;
        for(auto v : grid){
            auto n = upper_bound(v.begin(), v.end(), 0, greater<int>());
            count += v.end()-n;
        }
        return count;
    }
};
