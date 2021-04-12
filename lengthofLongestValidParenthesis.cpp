class Solution {
public:
    int longestValidParentheses(string s) {
        /* Dynamic Programming::
        vector<int> dp(s.size()+1,0);
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i]=((i-2)>=0 ? dp[i-2] : 0) +2;
                }
                else{
                    if((i-dp[i-1])>0 && s[i-dp[i-1]-1]=='('){
                        dp[i]=dp[i-1]+2+((i-dp[i-1]-2)>=0 ? dp[i-dp[i-1]-2] : 0);
                    }
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
        */
        //stack::
        if(s == ""){
            return 0;
        }
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if(st.empty())st.push(i);
                else ans = max(ans, i-st.top());
            }
        }
        return ans;
    }
};
