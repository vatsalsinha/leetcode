class Solution {
public:
    bool isPalindrome(int x) {
        //method1:
        //string X = to_string(x);
        //string X1 = to_string(x);
        //reverse(X1.begin(), X1.end());
        //if(X == X1){
        //    return true;
        //}
        //return false;
        //..........................................
        //method2
        if(x < 0){
            return false;
        }
        int temp = x;
        int temp1;
        long  res = 0;
        //count = count - 1;
        while(temp != 0 && res < INT_MAX){
            temp1 = temp%10;
            temp = temp / 10;
            res = res*10 + temp1;
        }
        if (res == x){
            return true;
        }
        return false;
    }
};
