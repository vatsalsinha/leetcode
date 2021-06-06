class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 1, countM = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1]+1)
                    count++;
                else{
                    countM = max(count, countM);
                    count = 1;
                }
            }
        }
        return max(count, countM);
    }
};
