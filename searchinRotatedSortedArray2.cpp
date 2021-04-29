class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 1 && nums[0] == target)
            return true;
        int left = 0, right;
        right = nums.size() - 1; 
        int mid;
        while(left <= right){
            mid = (left + right)/2;
            if(nums[mid] == target){
                return true;
            } 
            if(nums[left] == nums[mid] && nums[right] == nums[mid]){
                left++;
                right--;
                continue;
            }
            //left array 
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            //right array 
            else{
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};
