class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        stringstream n1(num1), n2(num2);
        int r1, i1, r2, i2;
        char c;
        n1 >> r1 >> c >> i1 >> c; // extract
        n2 >> r2 >> c >> i2 >> c;
        stringstream res;
        res << to_string(r1*r2 - i1*i2) << "+" << (r1*i2 + r2*i1) << "i"; // insert
        return res.str();
    }
};
