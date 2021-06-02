class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++){
            string tmp;
            while(s[i] != ' ' && i < s.length()){
                tmp += s[i];
                i++;
            }
            reverse(tmp.begin(), tmp.end());
            res += tmp + " ";
        }
        return res.substr(0, res.length()-1);
    }
};
