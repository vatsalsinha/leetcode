class Solution {
public:
    void backtrack(vector<string>& ans, string& s, int index){
        if(index == s.size()){
            ans.push_back(s);
            return;
        }
        if(isalpha(s[index])){
            s[index] = toupper(s[index]);
            backtrack(ans, s, index+1);
            s[index] = tolower(s[index]);
            backtrack(ans, s, index+1);
        }
        else
            backtrack(ans, s, index+1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        backtrack(ans, s, 0);
        return ans;
    }
};
