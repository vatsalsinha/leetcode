class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(int i = 0; i < nums.size(); i++){
            if(hashSet.find(nums[i]) != hashSet.end())
                hashSet.erase(nums[i]);
            else
                hashSet.insert(nums[i]);
        }        
        auto it = hashSet.begin();
        return *it;
    }
};
