class Solution {
public:
    bool isPalindrome(string str){
         int i = 0;
         int j = str.size() - 1; 

         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }

         return true;
     }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); i++){
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        if(dict.find("") != dict.end()){
            for(int i = 0; i < words.size(); i++){
                if(i == dict[""])
                    continue;
                if(isPalindrome(words[i]))
                    ans.push_back({dict[""],i});
            }
        }
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j, words[i].size()-j);
                if(dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i)
                    ans.push_back({i, dict[left]});
                if(dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i)
                    ans.push_back({dict[right], i});
            }
        }
        return ans;
    }
};
