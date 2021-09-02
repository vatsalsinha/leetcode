class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mp[26] = {1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};
        int mask = 0;
        int maxlen = 0;
        int seen[32]; // total no. of possible states ie 2^5
        memset(seen, -1, sizeof seen);
        for(int i = 0; i < s.size(); i++){
            mask = mask ^ mp[s[i]-'a'];
            if(mask != 0 && seen[mask] == -1)
                seen[mask] = i;
            maxlen = max(maxlen, i-seen[mask]);
        }
        return maxlen;
    }
};
