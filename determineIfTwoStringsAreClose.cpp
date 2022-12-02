class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> s1, s2;
        vector<int> mp1(26, 0), mp2(26,0);
        for(int i = 0; i < word1.size(); i++){
            mp1[word1[i] - 'a']++;
            s1.insert(word1[i]);
        }
        for(int i = 0; i < word2.size(); i++){
            mp2[word2[i] - 'a']++;
            s2.insert(word2[i]);
        }
        sort(mp1.begin(), mp1.end());
        sort(mp2.begin(), mp2.end());
        return mp1==mp2 && s1==s2;
    }
};
