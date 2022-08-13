class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> count;
        for(auto wrd : words)
            count[wrd]++;
        
        vector<int> ans;
        for(int i = 0; i < s.size()-words.size()*words[0].size() + 1; i++){ //optimizing the loop to start search for substrings that can have the number of characters sames as the length of the word after concatenating the words in vector "words"
            unordered_map<string, int> mp;
            int j = 0;
            for(; j < words.size(); j++){
                string wrd = s.substr(i+j*words[0].size(), words[0].size());
                if(count.find(wrd) != count.end()){
                    mp[wrd]++;
                    if(mp[wrd] > count[wrd])
                        break;
                }
                else
                    break;
            }
            if(j == words.size())
                ans.push_back(i);
            }
        return ans;
    }
};
