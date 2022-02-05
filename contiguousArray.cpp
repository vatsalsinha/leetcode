class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, sum = 0;
        unordered_map<int, int> mp; // sum : index
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] == 1 ? 1 : -1;
            if(mp.find(sum) != mp.end()){
                int len = i - mp[sum];
                ans = max(ans, len);
            }
            else
                mp[sum] = i;
        }
        return ans;
    } 
};
