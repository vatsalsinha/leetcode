class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i: asteroids){
           // if asteroid in starting is only from left then no collision will happen
            if(i > 0 || st.empty())
                st.push(i);
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(i))
                    st.pop();
                if(!st.empty() && st.top() == abs(i))
                    st.pop();
                else{
                    if(st.empty() || st.top() < 0)
                        st.push(i);
                }
            }
        }
        vector<int> v;
        while(!st.empty()){
            int d = st.top();
            st.pop();
            v.push_back(d);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
