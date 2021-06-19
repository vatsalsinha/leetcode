class Solution {
public:
//     bool match(string word, string pattern){
//         unordered_map<char, char> mp1;
//         unordered_map<char, char> mp2;
//         for(int i = 0; i < word.size(); i++){
//              if(mp1.find(word[i]) == mp1.end()){
//                 mp1[word[i]] = pattern[i];
//             }
//             if(mp2.find(pattern[i]) == mp2.end()){
//                 mp2[pattern[i]] = word[i];
//             }
//             if(mp1[word[i]] != pattern[i] || mp2[pattern[i]] != word[i])
//                 return false;
//         }
//         return true;
        
//     }
//     vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
//         vector<string> ans;
//         for(auto w : words){
//             if(match(w, pattern))
//                 ans.push_back(w);
//         }
//         return ans;
//     }
    vector<string> findAndReplacePattern(vector<string> words, string p) {
        vector<string> res;
        for (string w : words) if (F(w) == F(p)) res.push_back(w);
        return res;
    }

    string F(string w) {
        unordered_map<char, int> m;
        for (char c : w) if (!m.count(c)) m[c] = m.size();
        for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
        return w;
    }
};
