class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // set<int> n(nums.begin(), nums.end());
        // vector<int> nums1(n.begin(), n.end());
        // return nums1.size() >= 3 ? nums1[nums1.size()-3] : nums1[nums1.size()-1];
        long fmax = LONG_MIN;
        long smax = LONG_MIN;
        long tmax = LONG_MIN;
        
        for(int i = 0; i < nums.size();i++){
            
            if(nums[i] == fmax || nums[i] == tmax|| nums[i] == smax){
                continue;
            }
            if(nums[i] > fmax ){
                
                tmax = smax;
                smax = fmax;
                fmax = nums[i];
                
            }
            else if(nums[i] > smax ){
                
                tmax = smax;
                smax = nums[i];
            }
            else if(nums[i] > tmax ){
                tmax = nums[i];
            }
        }
        
        if(tmax == LONG_MIN){
            return fmax;
        }
        
        return tmax;
    }
};
