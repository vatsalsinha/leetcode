class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        int num = 0;
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i]))
                num = num*10 + (s[i]-'0');
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == s.size()-1){
                if(s[i] == '+')
                    st.push(num);
                else if(s[i] == '-')
                    st.push(-num);
                else if(s[i] == '*'){
                    int sf = st.top();
                    st.pop();
                    st.push(sf*num);
                }
                else if(s[i] == '/'){
                    int sf = st.top();
                    st.pop();
                    st.push(sf/num);
                }
                num = 0;
            }
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
