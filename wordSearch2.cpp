class TrieNode{
public: 
    TrieNode* child[26];
    string wrd;
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    void build(vector<string> words){
        //TrieNode *curr = root;
        for(auto s : words){
            TrieNode* p = root;
            for(int i = 0; i < s.size(); i++){
                int index = s[i] - 'a';
                if(!p->child[index])
                    p->child[index] = new TrieNode();
                p = p->child[index];
            }
            p->wrd = s;
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& res){
        char c = board[i][j];
        if(c == '#' || p->child[c- 'a'] == NULL)
            return;
        p = p->child[c-'a'];
        if(p->wrd != ""){
            res.push_back(p->wrd);
            p->wrd = "";
        }
        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j ,p, res); 
        if (j > 0) dfs(board, i, j - 1, p, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, res); 
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, res);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        build(words);
        vector<string> res;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
};
