class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            int k = i+2;
            for(int j = i+1; j < nums.size()-1  && nums[i] != 0; j++){
                while(k < nums.size() && nums[i] + nums[j] > nums[k])
                    k++;
                count += k-j-1;
            }
        }
        return count;
    }
};
