class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26,0), vis(26,0);
        for(auto c : s){
            cnt[c-'a']++;
        }
        string ans = "";
        for(auto c : s){
            cnt[c-'a']--;
            if(!vis[c-'a']){ // if not visited
                while(ans.size() > 0 && ans.back() > c && cnt[ans.back()-'a'] > 0){ // sorting 
                    vis[ans.back()-'a'] = 0;
                    ans.pop_back();
                }
                vis[c-'a'] = 1;
                ans += c;
            }
        }
        return ans;
    }
};