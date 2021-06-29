class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //             INEFFICIENT BRUTE FORCE
        // int m = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     int sum = 0;
        //     for(int j = i; j < nums.size(); j++){
        //         sum += nums[j];
        //         int len = j-i+1;
        //         if(sum+k >= len)
        //             m = max(m,len);
        //     }
        // }
        // return m;
////////////////////////////////////////////////////////////////////////////////////////////////////////////    
        
        //APPROACH 2
        int start = 0, end = 0;
        int sum = 0, mx = INT_MIN;
        while(end < nums.size()){
            sum += nums[end];
            while(sum + k < end - start + 1){
                mx = max(mx, end-start);
                sum -= nums[start]; // excluding that element  from my window
                start++;
            }
            end++;
        }
        return max(mx, end-start);
        
        //APPROACH 1
        // int countZero = 0, ans = INT_MIN, j = -1;
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == 0)
        //         countZero++;
        //     while(countZero > k){
        //         j++;
        //         if(nums[j] == 0)
        //             countZero--;
        //     }
        //     int len = i-j;
        //     ans = max(ans, len);
        // }
        // return ans;
    }
};
