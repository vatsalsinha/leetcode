class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty() && (isupper(s[i]) && islower(st.top())) && tolower(st.top()) == tolower(s[i]))
                st.pop();
            else if(!st.empty() && (islower(s[i]) && isupper(st.top())) && tolower(st.top()) == tolower(s[i]))
                st.pop();
            else
                st.push(s[i]);
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
