class Solution {
public:
    int minOperations(string s) {
        int n0 = 0, n1 = 0;
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 0 && s[i] != '0')
                n0++;
            if(i % 2 == 1 && s[i] != '1')
                n0++;
        }
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 0 && s[i] != '1')
                n1++;
            if(i % 2 == 1 && s[i] != '0')
                n1++;
        }
        return min(n0, n1);
    }
};


