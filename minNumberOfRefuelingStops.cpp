class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //DP
        // vector<long> dp(stations.size()+1);
        // dp[0] = startFuel;
        // for (int i = 0; i < stations.size(); i++)
        // for (int j = i; j >= 0; j--) {
        //     if (dp[j] >= stations[i][0])
        //         dp[j+1] = max(dp[j+1], dp[j] + stations[i][1]);
        // }
        // for(int i = 0; i < dp.size(); i++){
        //     if(dp[i] >= target)
        //         return i;
        // }
        // return -1;
        
        //priority queue
        int i = 0, res;
        priority_queue<int>pq;
        for (res = 0; startFuel < target; res++) {
            while (i < stations.size() && stations[i][0] <= startFuel)
                pq.push(stations[i++][1]);
            if (pq.empty()) return -1;
            startFuel += pq.top(), pq.pop();
        }
        return res;
    }
};
