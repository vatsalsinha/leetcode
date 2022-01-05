class Solution {
public:
    bool isPal(string s, int i, int j){
        while(i < j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
    void backTrack(string s, vector<vector<string>>& ans, vector<string>& tmp, int index){
        if(index == s.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i = index; i < s.size(); i++){
            if(isPal(s, index, i)){// hint from striver(https://www.youtube.com/watch?v=WBgsABoClE0)
                tmp.push_back(s.substr(index, i-index+1));
                backTrack(s, ans, tmp, i+1);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        backTrack(s, ans, tmp, 0);
        return ans;
    }
};
