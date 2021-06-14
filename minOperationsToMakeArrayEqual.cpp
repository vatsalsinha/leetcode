class Solution {
public:
    int minOperations(int n) {
        //naive approach
        // if(n == 1)
        //     return 0;
        // vector<int> arr(n);
        // for(int i = 0; i < n; i++)
        //     arr[i] = (2*i) + 1;
        // int target = accumulate(arr.begin(), arr.end(), 0);
        // target /= n;
        // int count = 0;
        // for(int i = 0; arr[i] <= target; i++){
        //     count += target - arr[i];
        // }
        // return count;
        
        //optimised
        int count = 0;
        for(int i = 0; i < n/2; i++){
            count += n - (2*i + 1);
        }
        return count;
    }
};
