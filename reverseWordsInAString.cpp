class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string tmp;
        for(int i = s.length()-1; i > -1; i--){
            if(s[i] == ' ')
                continue;
            while(i > -1 && s[i] != ' '){
                tmp += s[i];
                i--;
            }
            reverse(tmp.begin(), tmp.end());
            res += tmp + " ";
            tmp = "";
        }
        int l = res.length()-1;
        return res.substr(0, l);
    }
};
