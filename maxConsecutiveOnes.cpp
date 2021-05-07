class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int tmp = 0;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == 1){
                tmp++;
                count = max(count, tmp);
            }
            else{
                tmp = 0;
            }
            i++;
        }
        return count;
    }
};
