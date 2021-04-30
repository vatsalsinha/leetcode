class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int rb[heights.size()], lb[heights.size()];
        stack<int> st;
        st.push(heights.size()-1);
        for(int i = heights.size()-1; i >= 0; i--){
            while(st.size() > 0 && heights[i] <= heights[st.top()]){
                st.pop();
            }
            rb[i] = st.empty() ? heights.size() : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < heights.size(); i++){
            while(st.size() > 0 && heights[i] <= heights[st.top()]){
                st.pop();
            }
            lb[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int ans = 0, tmp;
        for(int i = 0; i < heights.size(); i++){
            ans = max(ans, heights[i]*(rb[i]-lb[i]-1));
        }
        return ans;
    }
};
