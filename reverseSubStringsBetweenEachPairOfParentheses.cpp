class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string str;
        for(int i = 0; i < s.size(); i++){
            int start, end; string tmp;
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                reverse(s.begin() + st.top() + 1, s.begin()+i);
                st.pop();
            }
        }
        for(int i = 0; i < s.size(); i++){
                if(s[i] != ')' && s[i] != '(')
                    str += s[i];
        }
        return str;
    }
};
