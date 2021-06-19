class Solution {
public:
    int minAddToMakeValid(string s) {
        //approach 1
        // stack<char> st;
        // for(int i = 0; i < s.size(); i++){
        //     if(!st.empty() && s[i] == ')' && st.top() == '(')
        //         st.pop();
        //     else
        //         st.push(s[i]);
        // }
        // return (int)st.size();
        
        //approach 2 more optimised
        int left = 0, right = 0;
        for(char c : s){
            if(c == '(')
                right++;
            else if(right > 0)
                right--;
            else 
                left++;
        }
        return left+right;
    }
};
