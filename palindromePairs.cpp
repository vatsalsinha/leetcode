struct TrieNode {
    TrieNode *next[26] = {};
    int index = -1;
    vector<int> palindromeIndexes;
};
class Solution {
public:
    TrieNode root; // Suffix trie
    // bool isPalindrome(string s){
    //     int i = 0;
    //     int j = s.size()-1;
    //     while(i < j)
    //         if(s[i++] != s[j--])
    //             return false;
    //     return true;
    // }
    bool isPal(string& s, int i, int j){
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
            
    }
    void add(string &s, int i) {
        auto node = &root;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (isPal(s, 0, j)) node->palindromeIndexes.push_back(i); // A[i]'s prefix forms a palindrome
            int c = s[j] - 'a';
            if (!node->next[c]) node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->index = i;
        node->palindromeIndexes.push_back(i); // A[i]'s prefix is empty string here, which is a palindrome.
    }
    vector<vector<int>> palindromePairs(vector<string>& A) {
        //135/136 cases passed;
        // vector<vector<int>> ans;
        // unordered_map<string, int> umap;
        // for(int i = 0; i < words.size(); i++){
        //     string key = words[i];
        //     reverse(key.begin(), key.end());
        //     umap[key] = i;
        // }
        // if(umap.find("") != umap.end()){
        //     for(int i = 0; i < words.size(); i++){
        //         if(umap[""] == i)
        //             continue;
        //         if(isPalindrome(words[i]))
        //             ans.push_back({umap[""], i});
        //     }
        // }
        // for(int i = 0; i < words.size(); i++){
        //     for(int j = 0; j < words[i].size(); j++){
        //         string left = words[i].substr(0, j);
        //         string right = words[i].substr(j, words[i].size()-j);
        //         if(umap.find(left) != umap.end() && isPalindrome(right) && umap[left] != i)
        //             ans.push_back({i, umap[left]});
        //         if(umap.find(right) != umap.end() && isPalindrome(left) && umap[right] != i)
        //             ans.push_back({umap[right], i});
        //     }
        // }
        // return ans;
        int N = A.size();
        for (int i = 0; i < N; ++i) add(A[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < N; ++i) {
            auto s = A[i];
            auto node = &root;
            for (int j = 0; j < s.size() && node; ++j) {
                if (node->index != -1 && node->index != i && isPal(s, j, s.size() - 1)) ans.push_back({ i, node->index }); 
                // A[i]'s prefix matches this word and A[i]'s suffix forms a palindrome
                node = node->next[s[j] - 'a'];
            }
            if (!node) continue;
            for (int j : node->palindromeIndexes) { 
                // A[i] is exhausted in the matching above. 
                // If a word whose prefix is palindrome after matching its suffix with A[i], 
                // then this is also a valid pair
                if (i != j) ans.push_back({ i, j });
            }
        }
        return ans;
    }
};