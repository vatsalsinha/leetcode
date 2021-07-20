class Solution {
public:
    vector<int> og;
    Solution(vector<int>& nums) {
        og = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return og;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> n(og);
        //next_permutation(n.begin(), n.end());
        for(int i = 0; i < n.size(); i++){
            int pos = rand() % (n.size()-i);
            swap(n[pos+i], n[i]);
        }
        return n;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
