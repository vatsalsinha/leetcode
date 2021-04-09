class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            if(stk.size() > 0 && stk.top() == '(' && s[i] == ')')
                stk.pop();
            else if(stk.size() > 0 && stk.top() == '[' && s[i] == ']')
                stk.pop();
            else if(stk.size() > 0 && stk.top() == '{' && s[i] == '}')
                stk.pop();
            else{
                stk.push(s[i]);
            }
        }
        return stk.empty() ? true : false;
    }
};
