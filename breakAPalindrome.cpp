class Solution {
public:
    string breakPalindrome(string palindrome) {
        int i = 0, n = palindrome.size()-1;
        if(palindrome.size() == 1)
            return "";
        while(i < n){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
            i++;
            n--;
        }
        palindrome[palindrome.size()-1] = 'b';
        return palindrome;
    }
};
