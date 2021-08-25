class Solution {
public:
    bool judgeSquareSum(int c) {
         for(long a = 0; a * a <= c; a++){
             int b = c - (int)(a*a);
             int start = a;
             int end = b;
             long  mid;
             while(start <= end){
                 mid = start + (end - start) / 2;
                 if(mid*mid == b)
                     return true;
                 else if(mid*mid < b)
                     start = mid+1;
                 else
                     end = mid - 1;
             }
         }
        return false;
    }
};
