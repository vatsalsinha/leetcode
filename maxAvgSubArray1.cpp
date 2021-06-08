class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
	//running sum
        // vector<int> sum(nums.size());
        // sum[0] = nums[0];
        // for(int i = 1; i < nums.size(); i++){
        //     sum[i] = sum[i-1] + nums[i];
        // }
        // double res = sum[k-1]*1.0/k;
        // for(int i = k; i < nums.size(); i++){
        //    res = max(res, (sum[i] - sum[i-k])*1.0/k);
        // }
        // return res;

	//sliding window
        double sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        double res = sum;
        for(int i = k; i < nums.size(); i++){
            sum += nums[i]-nums[i-k];
            res = max(res, sum);
        }
        return res/k;
    }
};
