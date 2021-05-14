class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res;
        for(auto token : tokens){
                if(token == "+"){
                    int A = st.top();
                    st.pop();
                    int B = st.top();
                    st.pop();
                    res = A+B;
                    st.push(res);
                }            
                else if(token == "-"){
                    int A = st.top();
                    st.pop();
                    int B = st.top();
                    st.pop();
                    res = B-A;
                    st.push(res);
                }   
                else if(token == "*"){
                    int A = st.top();
                    st.pop();
                    int B = st.top();
                    st.pop();
                    res = A*B;
                    st.push(res);
                }   
                else if(token == "/"){
                    int A = st.top();
                    st.pop();
                    int B = st.top();
                    st.pop();
                    res = B/A;
                    st.push(res);
                }   
            else{
            st.push(stoi(token));
            }
        }
        return st.top();
    }
};
