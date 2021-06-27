class Solution {
public:
    string U = "abc";
    void backtrack(vector<string>& ans, string res, int n, int index, char prev){
        if(index == n){
            ans.push_back(res);
            return;
        }
        for(int i = 0; i < 3; i++){
            if(prev != U[i]){
                res += U[i];
                backtrack(ans, res, n, index+1, U[i]);
                res.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> ans;
        //string t;
        backtrack(ans, "", n, 0, '$');
        return k > ans.size() ? "" : ans[k-1];
    }
};
