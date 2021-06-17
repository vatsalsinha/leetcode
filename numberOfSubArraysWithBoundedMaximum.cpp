class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int count = 0;
        int lessThanLeft = 0;
        int lessThanEqRight = 0;
        for(auto n : nums){
            if(n < left)
                lessThanLeft++;
            else 
                lessThanLeft = 0;
            if(n <= right)
                lessThanEqRight++;
            else
                lessThanEqRight = 0;
            count += lessThanEqRight - lessThanLeft;
        }
        return count;
    }
};
