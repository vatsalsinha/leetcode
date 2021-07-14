class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(!st.empty())
                    st.pop();
                else
                    s[i] = '*'; // since we dont have a pair, we have to remove this
            }
            else if(s[i] == '(')
                st.push(i);
        }
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};
