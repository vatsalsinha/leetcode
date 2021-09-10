class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int count = 0;
        for(int i = 0; i < k; i++){
            if(isVowel(s[i]))
                count++;
        }
        int ans = count;
        for(int i = k; i < s.size(); i++){
            if(isVowel(s[i]))
                count++;
            if(isVowel(s[i-k]))
                count--;
            ans = max(ans, count);
        }
        return ans;
    }
};
