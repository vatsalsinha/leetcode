class Solution {
public:
    int myAtoi(string s) {
        int i = 0, result = 0;
        int sign_flag = 1; // + -> 1 | - -> -1;
        if(s.length() == 0){
            return 0;
        }
        while(i < s.length() && s[i] == ' '){
                i++;
        }
        if(i < s.length() && (s[i] == '+' || s[i] == '-')){
            sign_flag = (s[i++] == '+') ? 1 : -1;
        }
        while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
            //if(result > INT_MAX || result < INT_MIN){
             //   return (sign_flag == 1) ? INT_MAX : INT_MIN;
            //}
             if (result > INT_MAX / 10 ||
                    (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                return (sign_flag == 1) ? INT_MAX : INT_MIN; //checking for int overflow
            }
            result = result*10 + (s[i++]- '0');
            
        }
        return result*sign_flag;
    }
};
