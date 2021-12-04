    class TrieNode{
    public: 
        TrieNode* child[26];
        bool isEnd;
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                child[i] = NULL;
            }
        }
    };
    class StreamChecker {
    public:
        TrieNode* root;
        string str;
        void addWord(string word){
            reverse(word.begin(), word.end());
            TrieNode* curr = root;
            for(int i = 0; i < word.size(); i++){
                int index = word[i] - 'a';
                if(!curr->child[index])
                    curr->child[index] = new TrieNode;
                curr = curr->child[index];
            }
            curr->isEnd = true;
        }
        StreamChecker(vector<string>& words) {
            root = new TrieNode();
            for(int i = 0; i < words.size(); i++)
                addWord(words[i]);
        }
        // Note: everytime letter is getting appended
        bool query(char letter) {
            str += letter;
            TrieNode* curr = root;
            for(int i = str.size()-1; i > -1; i--){
                char c = str[i];
                int ind = c-'a';
                if(curr != NULL && curr->child[ind] != NULL){
                    curr=curr->child[ind];
                    if(curr->isEnd)
                        return true;
                }
                else{
                    return false;
                }
            }
            return false;
        }
    };

    /**
     * Your StreamChecker object will be instantiated and called as such:
     * StreamChecker* obj = new StreamChecker(words);
     * bool param_1 = obj->query(letter);
     */
