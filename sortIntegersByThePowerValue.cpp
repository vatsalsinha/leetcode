class Solution {
public:
    unordered_map<int, int> memo;
    int calculatePower(int x){
        // if(x==1)
        //     return 0;
        // int steps = 0;
        // while(x != 1){
        //     x = x % 2 ? 3*x+1 : x / 2;
        //     steps++;
        // }
        // return steps;
        if (x == 1) return 0;
        if (memo.count(x)) return memo[x];
        return memo[x] = 1 + (x % 2 ? calculatePower(x * 3 + 1) : calculatePower(x / 2));
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> dp;
        for(int i = lo; i < hi+1; i++){
                dp.push_back({calculatePower(i),i});
        }
        sort(dp.begin(), dp.end());
        return dp[k-1].second;
    }
};
