class Solution {
public:
    string removeDuplicates(string s, int k) {
       if(k == 1)
        return "";
    string ans = "";
    stack<pair<char, int>> st;
    for(int i = 0; i < s.size(); i++){
        if(st.empty())
            st.push({s[i], 1}); // default case is k for this char is 1
        else{
            if(s[i] == st.top().first){
                st.push({s[i], st.top().second+1});
                if(st.top().second == k){ // as soon as k becomes = st.top().second, pop all
                    int x = k;
                    while(x){
                        st.pop();
                        x--;
                    }
                }
            }
            else{
                st.push({s[i], 1}); // no match
            }
        }
    }
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
};

