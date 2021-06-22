class Solution {
public:
    bool isSub(string s, string t){
        int m = s.size();
        int n = t.size();
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == m;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map<string, int> umap;
        for(auto w : words)
            umap[w]++;
        for(auto it : umap){
            if(isSub(it.first, s))
                count += it.second;
        }
        return count;
    }
};
