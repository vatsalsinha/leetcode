class Solution {
public:
    int romanToInt(string s) {
        int temp = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'C' && s[i+1] == 'M'){
                temp += 900; i+=2;
            }
            if(s[i] == 'M'){
                temp += 1000;
            }
            if(s[i] == 'D'){
                temp += 500;
            }
            if(s[i] == 'C' && s[i+1] == 'D'){
                temp += 400; i+=2;
            }
            if(s[i] == 'C'){
                temp += 100;
            }
            if(s[i] == 'X' && s[i+1] == 'C'){
                temp += 90; i+=2;
            }
            if(s[i] == 'L'){
                temp += 50;
            }
            if(s[i] == 'X' && s[i+1] == 'L'){
                temp += 40; i+=2;
            }
            if(s[i] == 'X'){
                temp += 10;
            }
            if(s[i] == 'I' && s[i+1] == 'X'){
                temp += 9; i+=2;
            }
            if(s[i] == 'V'){
                temp += 5;
            }
            if(s[i] == 'I' && s[i+1] == 'V'){
                temp += 4; i+=2;
            }
            if(s[i] == 'I'){
                temp += 1;
            }
            else{
                temp += 0;
            }
            cout<<temp<<"+";
        }
        return temp;
    }
};
