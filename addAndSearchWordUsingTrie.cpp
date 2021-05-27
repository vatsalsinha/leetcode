class TrieNode{
public:
    TrieNode* child[26];
    bool isEndOfWord;
    TrieNode(){
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(!curr->child[index])
                curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->isEndOfWord=true;
    }
    
    bool dfs(TrieNode* curr, string &word, int start){
        if(curr == NULL)
            return false;
        if(start == word.length()){
            return curr->isEndOfWord;
        }
        char c = word[start];
        if(c == '.'){
            for(int i = 0; i < 26; i++){
                if(curr->child[i] != NULL)
                    if(dfs(curr->child[i], word, start+1))
                        return true;
            }
            return false;
        }
        else{
            return dfs(curr->child[c-'a'], word, start+1);
        }
    }
        
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
