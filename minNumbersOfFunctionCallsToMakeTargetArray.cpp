class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int currDivides = 0;
        int maxDivides = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            currDivides = 0;
            int n = nums[i];
            while(n > 0){
                if(n%2 == 0){
                    n = n >> 1;
                    currDivides++;
                    
                    if(currDivides > maxDivides){
                        count++;
                        maxDivides = currDivides;
                    }
                }
                else{
                    n--;
                    count++;
                }
            }
        }
        return count;
    }
};
