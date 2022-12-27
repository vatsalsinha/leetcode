class Solution {
public:
    
    // Iterate through all the strings
        //     a. If a string has frequency greater than 1 then skip it
        //     b. Otherwise, check if the string is a subsequence of all larger strings
        //        If it is not a subsequence of any larger string return its size
        //     c. If the longest string is unique, no need to check for subsequence just
        //         return its length
    bool static cmp(string s, string a){
        return s.size() > a.size();
    }
    bool isSubsequence(string s1, string s2){
        int i = 0, j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j])
                j++;
            i++;
        }
        return j == s2.size();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        unordered_map<string, int> mp;
        for(auto str : strs){
            mp[str]++;
        }
        for(int i = 0; i < strs.size(); i++){
            if(mp[strs[i]] > 1){
                continue;
            }
            else{
                if(!i)
                    return strs[i].size();
                for(int j = 0; j < i; j++){
                    if(!isSubsequence(strs[j], strs[i])){
                        if(j == i-1) // all possibilities checked.
                            return strs[i].size();
                    }
                    else
                        break;
                }
            }
        }
        return -1;
    }
};
