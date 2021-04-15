class Solution {
public:
    int trap(vector<int>& height) {
        /*
        TWO POINTER APPROACH
        int left_max = 0, left = 0, right = height.size()-1, right_max = 0, ans = 0;
        while(left < right){
            if(height[left] < height[right]){
                height[left] >= left_max ? left_max = height[left] : ans += left_max - height[left] ;
                left++;
            }
            else{
                height[right] >= right_max ? right_max = height[right] : ans += right_max - height[right];
                right--;
            }
        }
        return ans;
        */
        if(height.size() == 0){
            return 0;
        }
        vector<int> left_max(height.size()), right_max(height.size());
        int ans=0;
        left_max[0] = height[0];
        right_max[height.size()-1] = height[height.size()-1];
        for(int i = 1; i < height.size(); i++){
            left_max[i] = max(height[i], left_max[i-1]);
        }
        for(int i = height.size()-2; i >= 0; i--){
            right_max[i] = max(height[i], right_max[i+1]);
        }
        for(int i = 0; i < height.size()-1; i++){
            ans += min(right_max[i], left_max[i]) - height[i];
        }
        return ans;
    }
};
