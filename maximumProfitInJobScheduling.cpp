class Solution {
public:
    struct job{
        int start;
        int end;
        int profit;
    };
    bool static cmp(job j1, job j2){
         return j1.end < j2.end;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<job> job(n);
        for(int i = 0; i < n; i++){
            job[i].start = startTime[i];
            job[i].end = endTime[i];
            job[i].profit = profit[i];
        }
        sort(job.begin(), job.end(), cmp);
        int ans = 0; 
        vector<int> dp(n);
        dp[0] = job[0].profit;
        for(int i = 1; i < n; i++){
            int f = 0;
            for(int j = i-1; j >= 0; j--){
                if(job[i].start >= job[j].end){
                    f = dp[j];
                    break;
                }
            }
            dp[i] = max(dp[i-1], f + job[i].profit);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
