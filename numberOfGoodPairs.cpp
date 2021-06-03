class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int i = 0, j;
        // int count = 0;
        // for(int i = 0; i < nums.size()-1; i++){
        //     for(int j = i+1; j < nums.size(); j++){
        //         if(nums[i] == nums[j])
        //             count++;
        //     }
        // }
        // return count;
        unordered_map<int, int> umap;
        int count = 0;
        for(int i : nums){
            count += umap[i]++;
        }
        return count;
    }
};
