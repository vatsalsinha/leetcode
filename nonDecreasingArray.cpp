class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            //decreasing sequence 
            if(nums[i-1] > nums[i]){
                count++;
                //if prev of prev is greater than curr then we have to make the lesser equal to greater (curr = prev)
                if(i >= 2 && nums[i-2] > nums[i])
                    nums[i] = nums[i-1];
                //if prev of prev element of curr is less than or equal to it then only the we can make it non decreasing by making the greater equal to lesser (prev = curr).
                else
                    nums[i-1] = nums[i];
            }
        }
        return count<=1;
    }
};
