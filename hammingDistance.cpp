class Solution {
public:
    int hammingDistance(int x, int y) {
        int c = x^y;
        int count = 0;
        while(c){
            c = c & (c-1);
            count++;
        }
        return count;
    }
};
