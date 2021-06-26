class CombinationIterator {
public:
    vector<string> per;
    string ls;
    int len;
    int i = 0;
    void backtrack(string s, string& res, int index){
        if(res.length() == len){
            per.push_back(res);
            return;
        }
        for(int i = index; i < s.length(); i++){
            res += s[i];
            backtrack(s, res, i+1);
            res.pop_back();
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        //s = characters;
        len = combinationLength;
        backtrack(characters, ls, 0);
    }
    
    string next() {
        return per[i++];
    }
    
    bool hasNext() {
        return i < per.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
