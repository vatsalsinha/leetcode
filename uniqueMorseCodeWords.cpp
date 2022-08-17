class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(auto wrd : words){
            string s;
            for(auto c : wrd){
                s += morse[c-'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};
