class Solution {
public:
    bool possible(int index, int mid, int maxSum, int n){
        long long sum = mid*(mid+1);
        sum -= mid;
        int el_left = index+1;
        int el_right = n-index;
        sum -= el_left >= 0 ? (long long)el_left*(el_left+1)/2 : el_left;
        sum -= el_right >= 0 ? (long long)el_right*(el_right+1)/2 : el_right;
        return sum <= maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(possible(index, mid, maxSum, n)){
                if(possible(index, mid+1, maxSum, n))
                    low = mid+1;
                else
                    ans = mid;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};
