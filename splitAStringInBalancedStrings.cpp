class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int balance = 0;
        for(auto c : s){
            if(c == 'L')
                balance++;
            else
                balance--;
            if(balance == 0)
                ans++;
        }
        return ans;
    }
};
