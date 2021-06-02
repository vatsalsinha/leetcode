class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int> n;
        // k = k % nums.size();
        // for(int i = nums.size()-k; i < nums.size(); i++)
        //     n.push_back(nums[i]);
        // for(int i = 0; i < nums.size()-k; i++){
        //     n.push_back(nums[i]);
        // }
        // nums = n;
        int n = nums.size();
        k %= n;
        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        reverse(nums.begin(), nums.begin()+n-k);
        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        reverse(nums.begin()+n-k, nums.begin() + n);
        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        reverse(nums.begin(), nums.end());
    }
};
