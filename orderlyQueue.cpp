class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        for(int i = 1; i < s.size(); i++){
            res = min(s.substr(i) + s.substr(0,i), res);
        }
        return res;
    }
};
