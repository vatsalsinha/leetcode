class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        int minDiff = INT_MAX, pos = -1;
        vector<long long> preSum(n+1, 0);
        for(int i = 1; i < n+1; i++){
            preSum[i] = preSum[i-1] + nums[i-1]; 
        }
        for(int i = 1; i < n+1; i++){
            long long soFar = preSum[i], diff;
            long long till_i = preSum[n] - preSum[i];
            if(i == n){
                till_i = 0;
                diff = abs(soFar / n);
            }
            else
                diff = abs(soFar/i - till_i/(n-i));
            if(diff < minDiff){
                minDiff = diff;
                pos = i-1;
            }
        }
        
        return pos;
    }
};

// 0 2 7 10 19 24 27
// 0 1 2 3  4  5  6   <-i