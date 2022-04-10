class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto str : ops){
            if(str != "C"){
                if(str == "D")
                    st.push(st.top()*2);
                else if(str == "+"){
                    int t = st.top();
                    st.pop();
                    int t2 = st.top();
                    st.push(t);
                    st.push(t+t2);
                }
                else{
                    st.push(stoi(str));
                }
            }
            else{
                st.pop();
            }
        }
        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
