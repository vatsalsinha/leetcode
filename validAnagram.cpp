class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        // if(s.size() != t.size())
        //     return false;
        // unordered_map<char, int> dict;
        // for(int i = 0; i < s.size(); i++){
        //     dict[s[i]]++;
        //     dict[t[i]]--;
        // }
        // for(auto it : dict){
        //     if(it.second)
        //         return false;
        // }
        // return true;
    }
};
