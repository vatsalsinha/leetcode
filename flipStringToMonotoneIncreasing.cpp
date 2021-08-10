class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0, ones = 0;
        for(auto c : s){
            if(c == '1')
                ones++;
            else
                ans++;
            ans = min(ans, ones);
        }
        return ans;
    }
};
