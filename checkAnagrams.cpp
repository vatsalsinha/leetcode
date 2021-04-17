class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> tmp = strs;
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        // sort the strings and check for anagrams. pairs have same character count
        for(int i = 0; i < tmp.size(); i++){
            sort(tmp[i].begin(), tmp[i].end());
        }
        for(int i = 0; i < tmp.size(); i++){
            mp[tmp[i]].push_back(strs[i]);
        }
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
