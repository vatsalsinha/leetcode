class TrieNode{
public:
    TrieNode* child[27];
    int weight;
    TrieNode(){
        for(int i = 0; i < 27; i++)
            child[i] = NULL;
        weight = 0;
    }
    void insert(string s, int wt){
        TrieNode* node = this;
        for(char c : s){
            if(node->child[c-'a'] == NULL)
                node->child[c-'a'] = new TrieNode();
            node = node->child[c-'a'];
            node->weight = wt;
        }
    }
    int startsWith(string s){
        TrieNode* node = this;
        for(char c : s){
            if(node->child[c-'a'] == NULL)
                return -1;
            node = node->child[c-'a'];
        }
        return node->weight;
    }
};
class WordFilter {
public:
    TrieNode trie;
    WordFilter(vector<string>& words) {
        int idx = 0;
        for(string word : words){
            trie.insert(word, idx);
            string tmp = "{" + word;
            for(int i = word.size()-1; i > -1; i--){
                string newWrd = word[i]+tmp;
                tmp = newWrd;
                trie.insert(newWrd, idx);
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        string w = suffix+"{"+prefix;
        return trie.startsWith(w);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
