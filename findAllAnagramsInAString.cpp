class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> curr(26), goal(26), ans;
        for(auto c : p)
            goal[c-'a']++;
        for(int i = 0; i < s.size(); i++){
            curr[s[i]-'a']++;
            if(i >= p.size())
                curr[s[i-p.size()]-'a']--;
            if(curr == goal)
                ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};
