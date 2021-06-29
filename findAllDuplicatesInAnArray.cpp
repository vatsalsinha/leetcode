class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // vector<int> ans;
        // unordered_map<int,int> umap;
        // for(auto n : nums){
        //     umap[n]++;
        //     if(umap[n] >= 2){
        //         ans.push_back(n);
        //     }
        // }
        // return ans;
        
        //faster approach
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            if(nums[abs(nums[i])-1] > 0)
                res.push_back(abs(nums[i]));
        }
        return res;
    }
};
