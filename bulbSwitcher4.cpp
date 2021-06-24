class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        char s = '0';
        for(auto c : target){
            if(s != c){
                count++;
                s = c;
            }
        }
        return count;
    }
};
