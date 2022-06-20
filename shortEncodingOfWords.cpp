class TrieNode{
public:
    TrieNode* child[26];
    TrieNode(){
        TrieNode* trie = this;
        for(int i = 0; i < 26; i++){
            trie->child[i] = NULL;
        }
    }
    bool shouldBeAdded(string word){
        TrieNode* trie = this;
        bool isNeeded = false;
        for(int i = word.size()-1; i > -1; i--){
            char c = word[i];
            if(trie->child[c-'a'] == NULL){
                isNeeded = 1;
                trie->child[c-'a'] = new TrieNode();
            }
            trie = trie->child[c-'a'];
        }
        return isNeeded;
    }
};
class Solution {
public:
    bool static cmp(string a, string b){
        return b.size()<a.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        sort(words.begin(), words.end(), cmp);
        TrieNode* trie = new TrieNode();
        for(auto wrd : words){
            if(trie->shouldBeAdded(wrd))
                ans += wrd.size()+1;
        }
        return ans;
    }
};

/*
make a trie
add each word to the trie
if a word is a substring of the word, then dont add to the trie
calculate the word length of the current word and add it to answer appending a '#'
*/
