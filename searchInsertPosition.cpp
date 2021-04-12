class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int> ans = nums;
        ans.push_back(target);
        sort(ans.begin(), ans.end());
        // stl:
        // auto it = find(ans.begin(), ans.end(), target);
        // int index = it - ans.begin();
        // return index;
        //binary search
        int low = 0, high = ans.size()-1, pos;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(ans[mid] == target){
                pos = mid;
            }
            if(ans[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return pos;
    }
};
