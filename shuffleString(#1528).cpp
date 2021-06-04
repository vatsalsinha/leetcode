class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        // string res;
        // map<int, char> mp;
        // for(int i = 0; i < indices.size(); i++){
        //     mp[indices[i]] = s[i];
        // }
        // for(auto it : mp){
        //     res += it.second;
        // }
        // return res;
        string res = s;
        for(int i = 0; i < indices.size(); i++){
            res[indices[i]] = s[i];
        }
        return res;
    }
};
