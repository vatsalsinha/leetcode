class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-2; // because if high is n-1, it wont shrink if the ans is the last element
        // In every duplicate element, first occurrence is in the even index and the second occurence is in the odd index. So we use
        // this fact, and check where currently is the mid. If mid is even, then we check mid+1 and if it is same, shrink low
        // similarly if mid is odd, then we check mid-1 and if it is same, shrink low.
        // ELSE shrink high
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == nums[mid^1]) // mid^1 : mid%2 == 0 ? mid+1 : mid-1
                low = mid + 1;
            else
                high = mid-1;
        }
        return nums[low];
    }
};
