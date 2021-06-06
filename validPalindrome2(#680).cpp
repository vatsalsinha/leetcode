class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while(i < j){
            // if the characters are not equal, check whether the substring forms a palindrome
            // it should form a palindrome if we remove either one character
            if(s[i] != s[j]){
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
            i++;
            j--;
        }
        return true;
    }
};
