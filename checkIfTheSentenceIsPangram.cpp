class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> v(26, 0);
        for(auto c : sentence)
            v[c-'a'] = 1;
        return accumulate(v.begin(), v.end(), 0) == 26;
    }
};
