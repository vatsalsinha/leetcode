class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto i : s){
            if(!st.empty() && isalpha(st.top()) && isdigit(i)){
                st.pop();
            }
            else
                st.push(i);
        }
        string ans;
        ans.resize((int)st.size());
        for(int i = st.size()-1; i > -1; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
