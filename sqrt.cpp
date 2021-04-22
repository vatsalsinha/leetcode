class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1){
            return x;
        }
        int start = 1, end = x, ans, mid;
        while(start <= end){
            mid = start + ((end - start) / 2);
            if(mid == x/mid){
                return mid;
            }
            if(mid < x/mid){
                start = mid + 1;
                ans = mid;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};
