class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        string s = strs[0]; string pref;

    // vector<string> pref;
        for(int i = 1; i < strs.size(); i++){
            int j = 0;
            pref = "";
            while(j < s.size() && strs[i][j] == s[j]){
                pref += s[j];
                j++;
            }
            s = pref;
        }
        return s;
    }
};
