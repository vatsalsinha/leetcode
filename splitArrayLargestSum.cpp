class Solution {
public:
    bool ok(vector<int> nums, int max, int cuts){
        int acc = 0;
        for(auto n : nums){
            if(n > max)
                return false;
            else if(acc + n <= max)
                acc += n;
            else{
                --cuts;
                acc = n;
                if(cuts < 0)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int start = 0, end = 0;
        for(int i = 0; i < nums.size(); i++){
            start = max(start, nums[i]);
            end += nums[i];
        }
        while(start < end){
            long long mid = start + (end - start) / 2;
            if(ok(nums, mid, m-1)){
                end = mid;
            }
            else
                start = mid + 1;
        }
        return start;
    }
};
