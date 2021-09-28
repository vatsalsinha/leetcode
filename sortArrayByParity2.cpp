class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd, even;
        for(auto n : nums){
            if(n % 2 == 0)
                even.push_back(n);
            else
                odd.push_back(n);
        }
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i%2 == 0){
                ans[i] = even.back();
                even.pop_back();
            }
            else{
                ans[i] = odd.back();
                odd.pop_back();
            }
        }
        return ans;
    }
};
