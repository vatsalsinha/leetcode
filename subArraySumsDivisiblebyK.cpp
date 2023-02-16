class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        mp[0] = 1;
        int sum = 0, rem = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            rem = sum%k;
            if(rem < 0)
                rem += k;
            if(mp.find(rem) != mp.end()){
                count += mp[rem];
                mp[rem]++;
            }
            else{
                mp[rem] = 1;
            }
        }
        return count;
    }
};
