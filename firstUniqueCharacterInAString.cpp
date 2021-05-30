class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dict;
        for(int i = 0; i < s.size(); i++){
            dict[s[i]]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(dict[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
