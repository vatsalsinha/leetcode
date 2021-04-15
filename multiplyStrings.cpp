class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        string res(num1.size()+num2.size(), '0');
        int i = num1.size()-1;
        for(int i = num1.size()-1; i >=0; i--){
            for(int j = num2.size()-1; j>=0; j--){
                int prod = (num1[i]-'0')*(num2[j]-'0') + (res[i+j+1]-'0');
                int carry = prod / 10;
                int rem = prod % 10;
                res[i+j+1] = rem+'0';
                res[i+j] = (carry + (res[i+j]-'0')) + '0';
            }
        }
        // int it = res.find_first_not_of("0");
        // return ( it < 0  ? "0" : res.substr(it) );
        i = -1;
        while( ++i < res.size() && res[i] == '0');
        return res.substr(i);
    }
};
