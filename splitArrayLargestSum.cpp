class Solution {
public:
    //BINARY SEARCH APPROACH
    // ok function calculates min(sum(nums[1..j]), sum(nums[j+1....n]))
    bool ok(vector<int> nums, int max, int cuts){
        int acc = 0;
        for(auto n : nums){
            // If the current processed element in this array is larger than 'max', we cannot segment the array.
            // (Reason is straightforward, if 'nums' is [10, 2, 3, 5] and 'max' is 6, even you can have 3 cuts
            // (by which you can cut array as [[10], [2], [3], [5]]), the group containing 10 will be larger than 6, 
            //  there is no way to do this).
            // Ps: This step is unnecessary in this solution. Because 'left' in the splitArray() function can assure 
            // 'max' will be larger than every single element. I just want to write a generalized doable() function :)
            if(n > max)
                return false;
            // If the (sum of the currently processed group) + (current element) is smaller than max, we can add current 
            // element into this group.
            else if(acc + n <= max)
                acc += n;
            // If not, we will make a cut before this element, and this element will be the first element in the new group.
            else{
                --cuts;
                acc = n;
                // If we've used up all cuts, this means this 'max' is not doable.
                if(cuts < 0)
                    return false;
            }
        }
         // If we can reach here, this means we've used at most 'cuts' cut to segment the array, and the sum of each groups is
        // not larger than 'max'. Yeah!
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
        /* DYNAMIC PROGRAMMING APPROACH
        int n = nums.size();
        vector<unsigned int> prefixSum(n, 0);
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(m+1, INT_MAX));
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        for(int i = 0; i < n; i++){
            dp[i][1] = prefixSum[i];
        }
        dp[0][0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 2; j <= m; j++){
                for(int k = 0; k < i; k++){
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], prefixSum[i]-prefixSum[k]));
                }
            }
        }
        return dp[n-1][m];
        */
    }
};