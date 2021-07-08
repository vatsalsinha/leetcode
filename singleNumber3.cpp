class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {        
        //approach 1
        unordered_map<int, int> mp;
        vector<int> res;
        for(auto n : nums)
            mp[n]++;
        for(auto it : mp)
            if(it.second == 1)
                res.push_back(it.first);
        return res;
    }
};
