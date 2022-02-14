class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // sum : frequency
        int curSum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            curSum += nums[i];
            if(curSum == k)
                count++;
            if(mp.find(curSum-k) != mp.end()){
                count += mp[curSum-k];
            }
            mp[curSum]++;
        }
        return count;
    }
};

/* 
    [0, 1, 2, 3]
*/
