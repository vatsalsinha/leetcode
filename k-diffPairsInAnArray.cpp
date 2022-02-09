class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // binarySearch approach (O(nlogn))
        // int count = 0;
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++){
        //     if(i > 0 && nums[i] == nums[i-1])
        //         continue;
        //     bool res = binary_search(nums.begin()+i+1, nums.end(), k+nums[i]);
        //     if(res)
        //         count++;
        // }
        // return count;
        
        //unordered_map approach (O(n))
        unordered_map<int, int> mp;
        int count = 0;
        for(int i : nums)
            mp[i]++;
        // for(auto it : mp){
        //     if(k == 0 && it.second >= 2)
        //         count++;
        //     else{
        //         if(mp.find(it.first + k) != mp.end())
        //             count++;
        //     }
        // }
        if(k == 0){
            for(auto it : mp)
                if(it.second >= 2)
                    count++;
        }
        else{
            for(auto it : mp)
                if(mp.find(it.first + k) != mp.end())
                    count++;
        }
        return count;
    }
};