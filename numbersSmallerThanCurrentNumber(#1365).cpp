class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // int len = nums.size();
        // vector<int> res(len), copyV(nums);
        // // reading copyV to be binary-searched
        // sort(copyV.begin(), copyV.end());
        // for (int i = 0; i < len; i++) {
        //     res[i] = lower_bound(copyV.begin(), copyV.end(), nums[i]) - copyV.begin();
        // }
        // return res;
        map<int, int> mp;
        vector<int> copyV = nums;
        sort(copyV.begin(), copyV.end());
        for(int i = copyV.size()-1; i > -1; i--)
            mp[copyV[i]] = i;
        for(int i = 0; i < nums.size(); i++){
            nums[i] = mp[nums[i]];
        }
        return nums;
    }
};
