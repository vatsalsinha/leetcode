class Solution {
public:
    // bool ok(vector<int> nums, int mid, int k){
    //     int total = 0, j = 1;
    //     for(int i = 0; i < nums.size(); i++){
    //         while(j < nums.size() && nums[j]-nums[i] <= mid)
    //             j++;
    //         j--;
    //         int x = j-i;
    //         total += x;
    //     }
    //     return total >= k;
    // }
    int smallestDistancePair(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // int l = 0;
        // int diff = nums[nums.size()-1]-nums[0];
        // int r = diff;
        // while(l < r){
        //     int mid = l + (r-l)/2;
        //     if(ok(nums, mid, k))
        //         r = mid;
        //     else
        //         l = mid + 1;
        // }
        // return l;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[nums.size()-1]-nums[0];
        for(int count = 0; l < r; count = 0){
            int mid = l +(r-l)/2;
            for(int i = 0, j = 0; i < nums.size(); i++){
                while(j < nums.size() && nums[j] - nums[i] <= mid)
                    j++;
                count += j-i-1;
            }
            if(count < k)
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};
