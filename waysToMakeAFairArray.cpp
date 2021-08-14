class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        /* 
        Compute the Even-indexed value sum of the array without that element by adding up:
a. The originally Even-indexed value sum of the elements before the removed one.
b. The originally Odd-indexed value sum of the elements after the removed one.
Compute the Odd-indexed value sum of the array without that element by adding up:
a. The originally Odd-indexed value sum of the elements before the removed one.
b. The originally Even-indexed value sum of the elements after the removed one.
If the Even-indexed value sum and the Odd-indexed value sum are equal, add 1 to the solution.
        */
        int n = nums.size();
        if(n == 1)
            return 1;
        vector<int> preEven(n);
        vector<int> preOdd(n);
        vector<int> sufEven(n);
        vector<int> sufOdd(n);
        for(int i = 0, j = n-1; i < n && j > -1; i++, j--){
            if(i%2){
                preOdd[i] = i == 0 ? nums[i] : preOdd[i-1] + nums[i];
                preEven[i] = i == 0 ? 0 : preEven[i-1];
            }
            else{
                preOdd[i] = i == 0 ? 0 : preOdd[i-1];
                preEven[i] = i == 0 ? nums[i] : preEven[i-1] + nums[i];
            }
            if(j % 2){
                sufOdd[j] = j == n-1 ? nums[n-1] : sufOdd[j+1] + nums[j];
                sufEven[j] = j == n-1 ? 0 : sufEven[j+1];
            }
            else{
                sufOdd[j] = j == n-1 ? 0 : sufOdd[j+1];
                sufEven[j] = j == n-1 ? nums[j] : sufEven[j+1] + nums[j];
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(sufEven[i+1] == sufOdd[i+1])
                    count++;
            }
            else if(i == n-1){
                if(preEven[i-1] == preOdd[i-1])
                    count++;
            }
            else{
                if(preEven[i-1] + sufOdd[i+1] == preOdd[i-1] + sufEven[i+1])
                    count++;
            }
        }
        return count;
    }
};
