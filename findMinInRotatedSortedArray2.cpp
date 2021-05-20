class Solution {
public:
    int findMin(vector<int>& nums) {
        // set<int> j(nums.begin(), nums.end());
        // vector<int> num(j.begin(), j.end());
        // int start = 0, end = num.size()-1;
        // while(start < end){
        //     int mid = start + (end - start) / 2;
        //     if(num[mid] < num[start]){
        //         start = mid + 1;
        //     }
        //     else{
        //         end = mid;
        //     }
        // }
        // return num[start];
        int start = 0, end = nums.size()-1;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[end])
                start = mid + 1;
            else if(nums[mid] < nums[end])
                end = mid;
            else
                end--;
        }
        return nums[start];
    }
};
