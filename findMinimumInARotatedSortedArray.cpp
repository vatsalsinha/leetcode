class Solution {
public:
    int findMin(vector<int>& nums) {
        // auto it = min_element(nums.begin(), nums.end());
        // int pivot = it - nums.begin();
        // return nums[pivot];
        int start = 0, end = nums.size()-1;
        while(start < end){
            int mid = start + (end-start)/2;
            if(nums[mid] > nums[end])
                start = mid + 1;
            else
                end = mid;
        }
        return nums[start];
    }
};
