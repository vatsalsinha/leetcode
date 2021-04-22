class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        string str = "";
        while(i >= 0 || j >= 0 || carry>0){
            int A = i>=0 ? a[i]-'0' : 0;
            int B = j>=0 ? b[j]-'0' : 0;
            int sum = A+B+carry;
            str += to_string(sum%2);
            carry = sum/2;
            i--;
            j--;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
