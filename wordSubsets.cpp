class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mp(26,0);
        for(auto str : words2){
            vector<int> tmp(26,0);
            for(char c : str){
                tmp[c-'a']++;
                mp[c-'a'] = max(mp[c-'a'], tmp[c-'a']);
            }
        }
        vector<string> ans;
        for(auto str : words1){
            vector<int> ump(26,0);
            for(char c : str){
                ump[c-'a']++;
            }
            bool flag = 1;
            for(int i = 0; i < 26; i++){
                if(mp[i] > ump[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag)
                ans.push_back(str);
        }
        return ans;
    }
};
