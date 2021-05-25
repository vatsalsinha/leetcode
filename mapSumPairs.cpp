class TrieNode{
public:
    int last;
    TrieNode* child[26];
    TrieNode(){
        last = 0;
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
class MapSum {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* curr = root;
        for(int i = 0; i < key.size(); i++){
            int index = key[i]-'a';
            if(!curr->child[index])
                curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->last = val;
    }
    
    void dfs(TrieNode* curr, int &sum){
        if(curr->last != 0)
            sum += curr->last;
        for(int i = 0; i < 26; i++)
            if(curr->child[i])
                dfs(curr->child[i], sum);
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        int res = 0;
        for(int i = 0; i < prefix.size(); i++){
            int index = prefix[i] - 'a';
            if(!curr->child[index])
                return res;
            curr = curr->child[index];
        }
        dfs(curr, res);
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
