class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size()-1; i > -1; i--){
            if((int(num[i])-48) % 2 == 1)
                return num.substr(0, i+1);
        }
        return "";
    }
};
