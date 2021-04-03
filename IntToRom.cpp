class Solution {
public:
    string intToRoman(int num) {
        string A[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int N[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int temp= num;
        string s = "";
        for(int i = 0; i < 13; i++){
            while(temp >= N[i]){
                s.append(A[i]);
                temp -= N[i];
            }
        }
        return s;
    }
};
