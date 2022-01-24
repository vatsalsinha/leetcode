class Solution {
public:
    // bool allCaps(string w){
    //     for(auto c : w){
    //         if(islower(c))
    //             return false;
    //     }
    //     return true;
    // }
    // bool allLower(string w, int s, int e){
    //     for(int i = s; i < e; i++){
    //         if(isupper(w[i]))
    //             return false;
    //     }
    //     return true;
    // }
    bool detectCapitalUse(string word) {
        //return allCaps(word) | allLower(word, 0, word.size()) | (isupper(word[0]) && allLower(word, 1, word.size()));
        int n = word.length();
        if (n == 1) {
            return true;
        }

        // case 1: All capital
        if (isupper(word[0]) && isupper(word[1])) {
            for (int i = 2; i < n; i++) {
                if (islower(word[i])) {
                    return false;
                }
            }
        // case 2 and case 3
        } else {
            for (int i = 1; i < n; i++) {
                if (isupper(word[i])) {
                    return false;
                }
            }
        }

        // if pass one of the cases
        return true;
    }
};
