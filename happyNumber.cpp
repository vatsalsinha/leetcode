class Solution {
public:
    set<int> st;
    bool isHappy(int n) {
        if(n == 1)
            return true;
        int sq_sum = 0;
        while(n > 0){
            sq_sum += (n%10)*(n%10);
            n /= 10;
        }
        if(st.find(sq_sum) != st.end())
            return false;
        st.insert(sq_sum);
        return isHappy(sq_sum);
    }
};
