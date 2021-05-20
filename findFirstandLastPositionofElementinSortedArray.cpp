class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> ans(2, -1);
//         int l = 0, r = nums.size()-1;
//         int c = count(nums.begin(), nums.end(), target);
//         c = c-1;
//         int pos = -1;
//         while (l <= r) {
//         int m = l + (r - l) / 2;
  
//         // Check if x is present at mid
//         if (nums[m] == target)
//             pos = m;
  
//         // If x greater, ignore left half
//         if (nums[m] < target)
//             l = m + 1;
  
//         // If x is smaller, ignore right half
//         else
//             r = m - 1;
//     }
//         if(pos != -1){
//             ans.clear();
//             ans.push_back(pos);
//             ans.push_back(pos+c);
//             return ans;
//         }
//         return ans;
        vector<int> ans(2, -1);
        if(nums.size() == 0)
            return ans;
        int i = 0, j = nums.size()-1;
        while(i < j){
            int mid = i + (j-i) / 2;
            if(nums[mid] < target)
                i = mid + 1;
            else 
                j = mid;
        }
        if(nums[i] != target){
            return ans;
        }
        else{
            ans[0] = i;
        }
        j = nums.size() - 1;
        while(i < j){
            int mid = i+1 + (j-i) / 2;
            if(nums[mid] > target){
                j = mid - 1;
            }
            else{
                i = mid;
            }
        }
        ans[1] = j;
        return ans;
    }
};