class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        struct TrieNode* child[26];
        bool isEnd;
    };
    TrieNode* node;
    Trie() {
        node = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = node;
        for(char c : word){
            if(curr->child[c-'a'] == NULL)
                curr->child[c-'a'] = new TrieNode();
            curr = curr->child[c-'a'];
        }
        curr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = node;
        for(char c : word){
            if(curr->child[c-'a'] == NULL)
                return false;
            curr = curr->child[c-'a'];
        }
        if(curr->isEnd == true)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = node;
        for(char c : prefix){
            if(curr->child[c-'a'] == NULL)
                return false;
            curr = curr->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
