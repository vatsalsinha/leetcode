class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> mp;
        for(auto n : nums2){
            while(!st.empty() && st.top() < n){
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }   
        for(auto n : nums1){
            mp.find(n) != mp.end() ? res.push_back(mp[n]) : res.push_back(-1);
        }
        return res;
    }
};
