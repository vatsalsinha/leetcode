class Solution {
public:
    // function for checking if the string stamp matches with substring starting from i in s
    bool isMatch(string &s, string stamp, int i){
        for(int j = 0; j < stamp.size(); j++){
            if(s[i+j] != '?' && s[i+j] != stamp[j])
                return false;
        }
        return true;
    }
    // function for replacing all the characters in substring starting from i in s with question mark, also finds the count
    void replace(string& s, string stamp, int i, int& count){
        for(int j = 0; j < stamp.size(); j++){
            if(s[i+j] == stamp[j]){
                count++;
            }
            s[i+j] = '?';
        }
    }
    vector<int> movesToStamp(string stamp, string target) {
        string s = target;
        vector<bool> visited(target.size(), 0);
        vector<int> res;
        int count = 0;
        while(count != target.size()){
            bool didStamp = 0;
            for(int i = 0; i < target.size() - stamp.size()+1; i++){// since we are going reverse, we are making sure stamp is possible in the target string or not
                if(!visited[i] && isMatch(s, stamp, i)){
                    replace(s, stamp, i, count);
                    visited[i] = 1;
                    res.push_back(i);
                    didStamp = 1;
                }
            }
            if(!didStamp)
                return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
