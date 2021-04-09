class Solution {
public:
    bool isValid(string res){
        stack<char> stk;
        for(int i = 0; i < res.size(); i++){
            if(stk.size() > 0 && stk.top() == '(' && res[i] == ')'){
                stk.pop();
            }
            else{
                stk.push(res[i]);
            }
        }
        return stk.empty() ? true : false;
    }
    void backtrack(vector<string> &ans, string res, int open, int close, int max){
        if(res.size() == 2*max){
            if(isValid(res))
                ans.push_back(res);
        }
        if(open < max){
            res += '(';
            backtrack(ans, res, open+1, close, max);
            res.pop_back();
        }
        if(close < max){
            res += ')';
            backtrack(ans, res, open, close+1, max);
            res.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;
        backtrack(ans, res, 0, 0, n);
        return ans;
    }
};
