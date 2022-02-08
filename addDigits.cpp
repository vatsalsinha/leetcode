class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
            if(num == 0 && sum > 9){
                num = sum;
                sum = 0;
            }
        }
        return sum;
    }
};

/*
    38 
    38 % 10 = 8
    sum = 8
    38 / 10 = 3
    3%10 = 3
    sum = 8+3 = 11
    num = 11
    
*/
