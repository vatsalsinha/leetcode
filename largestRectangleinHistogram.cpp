class Solution {
public:
    void fillLb(vector<int> heights, vector<int> &lb){
        stack<int> st;
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[i] <= heights[st.top()])
                st.pop();
            lb[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    void fillRb(vector<int> heights, vector<int> &rb){
        stack<int> st;
        for(int i = heights.size()-1; i > -1; i--){
            while(!st.empty() && heights[i] <= heights[st.top()])
                st.pop();
            rb[i] = st.empty() ? heights.size() : st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        if(heights.size() == 1){
            return heights[0];
        }
        vector<int> rb(heights.size()), lb(heights.size());
        fillLb(heights, lb);
        fillRb(heights,rb);
        int ans = 0;
        for(int i =0; i < heights.size(); i++){
            ans = max(ans, (rb[i]-lb[i]-1)*heights[i]);
        }
        return ans;
    }
};