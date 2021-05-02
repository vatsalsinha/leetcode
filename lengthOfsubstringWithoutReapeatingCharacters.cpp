class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i = 0, j = 0;
        set<char> st;
        while(i < s.length()){
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
                i++;
                ans = max(ans, int(st.size()));
            }
            else{
                st.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};
