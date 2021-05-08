class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int n = abs(nums[i]);
            if(nums[n-1] > 0){
                nums[n-1] = -nums[n-1];
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
        // vector<int> res;
        // set<int> st(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++){
        //     if(st.find(i+1) == st.end())
        //         res.push_back(i+1);
        // }
        // return res;
    }
};
