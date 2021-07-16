class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a || b || c){
            int ma = a % 2;
            int mb = b % 2;
            int mc = c % 2;
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
            if(ma && mb && mc == 0)
                count += 2;
            else if ((ma | mb) != mc)
                count++;
        }
        return count;
    }
};
