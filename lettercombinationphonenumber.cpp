class Solution {
public:
    vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(string digits, int pos, string tmp, vector<string> &res){
        if(pos == digits.size()){
            res.push_back(tmp);
            return;
        }
        for(auto c: m[digits[pos] - '2']){
            tmp += c;
            dfs(digits, pos+1, tmp, res);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        // 2: {a,b,c}
       //vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if(digits.size() == 0){
            return res;
        }
        string s;
        dfs(digits, 0, s, res);
        return res;
        
    }
};