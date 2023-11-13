class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string sortVowels(string s) {
        string ans = "", v = "";
        for(auto c : s){
            if(isVowel(c))
                v += c;
        }
        sort(v.begin(), v.end());
        for(int i = 0, j = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                ans += v[j++];
            }
            else
                ans += s[i];
        }
        return ans;
    }
};
