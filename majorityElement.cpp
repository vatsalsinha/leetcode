class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> dict;
        // for(int i = 0; i < nums.size(); i++){
        //     dict[nums[i]]++;
        // }
        // for(auto it : dict){
        //     if(it.second > nums.size()/2)
        //         return it.first;
        // }
        // return 0;
        int major = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(count == 0){
                count++;
                major = nums[i];
            }
            else if(major == nums[i])
                count++;
            else
                count--;
        }
        return major;
    }
};
