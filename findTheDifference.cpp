class Solution {
public:
    char findTheDifference(string s, string t) {
        // int i = 0;
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // while(i < s.size()){
        //     if(s[i] != t[i])
        //         return t[i];
        //     i++;
        // }
        // return t[t.size()-1];

        unordered_map<char, int> mp;
        for(auto c : t)
            mp[c]++;
        for(auto c : s){
           mp[c]--;
        }
        for(auto it : mp){
            if(it.second == 1)
                return it.first;
        }
        return 'a';
    }
};
