class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index = nums.size()-1;
        int start = 0, end = nums.size()-1;
        vector<int> res(nums.size());
        while(start <= end){
            if(abs(nums[start]) < abs(nums[end])){
                res[index--] = nums[end]*nums[end];
                end--;
            }
            else{
                res[index--] = nums[start]*nums[start];
                start++;
            }
        }
        return res;
    }
};
