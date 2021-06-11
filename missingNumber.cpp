class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //approach 1
        // int n = nums.size();
        // int e = n * (n+1) / 2;
        // int a = accumulate(nums.begin(), nums.end(), 0);
        // return e - a;
        
        //approach 2
        // unordered_set<int> st(nums.begin(), nums.end());
        // int n = nums.size()+1;
        // for(int i = 0; i < n+1; i++)
        //     if(st.find(i) == st.end())
        //         return i;
        // return -1;
        
        //approach 3
        int res = nums.size();
        for(int i = 0; i < nums.size(); i++){
            res ^= nums[i];
            res ^= i;
        }
        return res;
    }
};
