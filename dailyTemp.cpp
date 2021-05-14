class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int i = 0;
        vector<int> res(temperatures.size(), 0);
        for(auto t : temperatures){
            while(!st.empty() && temperatures[st.top()] < t){
                int top = st.top();
                st.pop();
                res[top] = i - top;
            }
            st.push(i++);
        }
        return res;
    }
};
