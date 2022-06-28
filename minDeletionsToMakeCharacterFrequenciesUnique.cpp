class Solution {
public:
    int dict[26];
    int minDeletions(string s) {
        //sorting on the basis of character frequency
        for(auto c : s)
            dict[c-'a']++;
        sort(s.begin(), s.end(), [&] (char a, char b){ return dict[a-'a'] > dict[b-'a'] || (dict[a-'a'] == dict[b-'a'] && a < b);});
        unordered_set<int> st;
        int ans = 0;
        for(int i = 0; i < 26; i++){
            while(dict[i] && st.find(dict[i]) != st.end()){
                dict[i]--;
                ans++;
            }
            st.insert(dict[i]);
        }
        return ans;
        
    }
};
