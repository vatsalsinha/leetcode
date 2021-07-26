class Solution {
public:
    bool checkPowersOfThree(int n) {
	//In case of 3, the remainders can be 0,1 or 2. So if at all the remainder is 2, we cannot represent n as sum of power 3.
        int t = n;
        while(t != 1){
            int r = t % 3;
            t /= 3;
            if(r == 2)
                return false;
        }
        return true;
    }
};
