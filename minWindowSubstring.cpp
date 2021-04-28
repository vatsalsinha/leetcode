class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto c : t)
            mp[c]++;
        int i = 0, j = 0, len = INT_MAX, start = 0, count = mp.size();
        while(j < s.size()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            if(count == 0){
                if(j-i+1 < len){
                    start = i;
                    len = j-i+1;
                }
                while(count == 0){
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] > 0){
                            count++;
                            if(j-i+1 < len){
                                start = i;
                                len = j-start+1;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        return len==INT_MAX ? "":s.substr(start, len);
    }
};
