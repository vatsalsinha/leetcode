class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i = num1.size()-1, j = num2.size()-1;
        int carry = 0;
        while(i > -1 || j > -1 || carry){
            int a = i > -1 ? num1[i--] - '0' : 0;
            int b = j > -1 ? num2[j--] - '0' : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            sum %= 10;
            res += to_string(sum);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
