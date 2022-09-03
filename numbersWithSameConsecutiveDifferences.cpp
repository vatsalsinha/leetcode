class Solution {
public:
    void backtrack(vector<int>& ans, int n, int k, int num){
        if(n == 0){
            ans.push_back(num);
            return;
        }
        for(int digit = 0; digit <= 9; digit ++) {
            // we do not want to add 0 at the first place.
            if (num == 0 && digit == 0) {
                continue;
            }
            int prevDigit = num % 10;
            // if curr digit is a valid digit, add to num and call dfs.
            if (num == 0) {
              backtrack(ans, n - 1, k, digit);  
            } 
            else if (abs(prevDigit - digit) == k) {
                backtrack(ans, n - 1, k, (num * 10) + digit);
            }   
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        backtrack(ans, n, k, 0);
        return ans;
    }
};
