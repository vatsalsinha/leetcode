class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //solution 1
        //next_permutation(nums.begin(), nums.end());
        
        //solution 2
        if(nums.size() < 2)
            return;
        // for eg nums [1,3,5,4,2]
        int i = nums.size()-2; // i = 3
        while(i>-1 && nums[i] >= nums[i+1])
            i--; // i = 1
        if(i >= 0){
            int j = nums.size()-1;
            while(nums[j] <= nums[i])
                j--; // j = 3
            swap(nums[i], nums[j]); // 1 4 5 3 2 something greater than starting with 1 3 ......
        }
        reverse(nums.begin()+i+1, nums.end()); // 1 4 2 3 5 to get the next lexicographically increasing number
    }
};
