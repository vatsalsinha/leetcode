class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> mp(26);
        int i = 0;
        for(auto c : order){
            mp[c-'a'] = i;
            i++;
        }
        for(int i = 0; i < words.size()-1; i++){
            for(int j = 0; j < words[i].size(); j++){
                if(j >= words[i+1].size())
                    return 0;
                if(words[i+1][j] != words[i][j]){
                    if(mp[words[i][j] - 'a'] > mp[words[i+1][j] - 'a'])
                        return 0;
                    else
                        break;
                }
            }
        }
        return 1;
    }
};
