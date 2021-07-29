class Solution {
public:
    /*
    If s1[i] and s2[i] are not the same then we can find 3 patterns:
xx and yy, we can perform a diagonal swap and the result will be xy xy or yx yx. In the case of the diagonal swap, we need to form pairs to solve the disproportion of this type. Swap required to restore a single pair is 1.

yy and xx, we can perform a diagonal swap and the result will be xy xy or yx yx. In the case of the diagonal swap, we need to form pairs to solve the disproportion of this type. Swap required to restore a single pair is 1.

yx and xy, we can perform a vertical swap and the result will be xx yy or yy xx and this type will be transformed into type 1 or type 2 problem and another diagonal swap to make them equal. we need to form pair to solve disproportion of this type. Swap required to restore a single pair is 2.
    */
    int minimumSwap(string s1, string s2) {
        int ans = 0;
        int count_X = 0, count_Y = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == 'x' && s2[i] == 'y')
                count_X++;
            else if(s1[i] == 'y' && s2[i] == 'x')
                count_Y++;
        }
        ans = count_X/2 + count_Y/2;
        if(count_X % 2 == 0 && count_Y % 2 == 0)
            return ans;
        else if((count_X + count_Y) % 2 == 0)
            return ans + 2;
        return -1;
    }
};
