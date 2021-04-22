class Solution {
public:
    int climbStairs(int n) {
        if(n == 2){
            return 2;
        }
        if(n == 3){
            return 3;
        }
        if(n == 1){
            return 1;
        }
        if(n <= 0){
            return 0;
        }
        // int sum =  climbStairs(n-1) + climbStairs(n-2);
        // return sum;
        vector<int> arr(n+1);
        arr[1] = 1;
        arr[2] = 2;
        for(int i = 3; i < n+1; i++){
            arr[i] = arr[i-2] + arr[i-1];
        }
        return arr[n];
    }
};
