class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        if(num == 2 || num == 3 || num == 5 || num == 6 || num == 7 || num == 8)
            return false;
        int start = 1, end = num;
        while(start <= end){
            long mid = start + (end - start) / 2;
            if(mid*mid == num){
                return true;
            }
            else if(mid*mid < num){
                start = (int) mid + 1;
            }
            else
                end = (int) mid - 1;
        }
        return false;
    }
};
