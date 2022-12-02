class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels =  {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 0, j = s.size()-1;
        int countA = 0, countB = 0;
        while(i <= j){
            if(vowels.count(s[i++]))
                countA++;
            if(vowels.count(s[j--]))
                countB++;
        }
        return countA == countB;
    }
};
