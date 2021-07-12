class Solution {
public:
    int scoreOfParentheses(string s) {
        /* if s[i] == '('
                push the current score to stack
                enter the next layer
                reset score
            else
                score would either be doubled or atleast 1. Thus we take max
                exit the current layer
                score += st.top() + max(score, 1)
        */
        stack<int> st;
        int score = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(score);
                score = 0;
            }
            else{
                int prev = st.top();
                st.pop();
                score += prev + max(score, 1);
            }
        }
        return score;
    }
};
