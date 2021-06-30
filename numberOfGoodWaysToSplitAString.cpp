class Solution {
public:
    bool goodSplit(vector<int>a, vector<int> b){
        int a1 = 0, b1 = 0;
        for(int i = 0; i < 26; i++){
            if(a[i])
                a1++;
            if(b[i])
                b1++;
        }
        return a1 == b1;
    }
    int numSplits(string s) {
        vector<int> l(26), r(26);
        int goodSplits = 0;
        for(int i = 0; i < s.size(); i++){
            l[s[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            r[s[i] - 'a']++;
            l[s[i] - 'a']--;
            if(goodSplit(l,r))
                goodSplits++;
        }
        return goodSplits;
    }
};
