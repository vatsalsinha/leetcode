class Solution {
public:
    int search(vector<int>& nums, int target) {
        // o(n):
        // auto it = find(nums.begin(), nums.end(), target);
        // int index;
        // if(it != nums.end()){
        //     index = it - nums.begin();
        // }
        // else 
        //     index = -1;
        // return index;
        //binary search: 
        auto it = min_element(nums.begin(), nums.end());
        int pivot = it - nums.begin();
        int left = 0, right;
        right = nums.size() - 1; 
        int mid, pos;
        while(left <= right){
            mid = (left + right)/2;
            pos = (mid+pivot)%nums.size();
            if(nums[pos] == target){
                return pos;
            }
            if(nums[pos] < target){
                left=mid+1; 
            }
            else{
                right = mid-1;
            }
        }
        return -1;
    }
};
