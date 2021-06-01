class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        auto it = max_element(nums.begin(), nums.end());
        int maxIndex = it-nums.begin();
        int maxNumber = *it;
        for(int i = 0; i < nums.size(); i++){
            if(2*nums[i] > maxNumber && i != maxIndex)
                return -1;
        }
        return maxIndex;
    }
};
