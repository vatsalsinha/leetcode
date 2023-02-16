struct TrieNode {
        TrieNode* child[26];
        bool isEnd;
        TrieNode() {
            for (int i = 0; i < 26; i ++) child[i] = NULL;
            isEnd = false;
        }  
    };
class Solution {
public:
    void insert(TrieNode* root, string key){
        TrieNode* curr = root;
        for (int i = 0; i < key.size(); i ++) {
            int idx = key[i] - 'a';
            if (curr->child[idx] == NULL)
                curr->child[idx] = new TrieNode();
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }
    bool dfs(TrieNode* root, string word, int index, int count){
        TrieNode* curr = root;
        if(index >= word.size())
            return count > 1;
        for(int i = index; i < word.size(); i++){
            if(curr->child[word[i]-'a'] == NULL)
                return 0;
            curr = curr->child[word[i]-'a'];
            if(curr->isEnd){
                if(dfs(root, word, i+1, count+1))
                    return 1;
            }
        }
        return 0;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector<string> ans;
        for(int i  = 0; i < words.size(); i++)
            insert(root, words[i]);
        for(auto wrd : words){
            if(dfs(root, wrd, 0, 0))
                ans.push_back(wrd);
        }
        return ans;
    }
};
