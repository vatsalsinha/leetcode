class Solution {
public:
    bool isPal(string s){
        string x(s.rbegin(), s.rend());
        return s == x;
    }
    bool isPalindrome(string s) {
        string tmp;
        for(auto c : s){
            if(isalnum(c))
                tmp += tolower(c);
            else
                continue;
        }
        cout<<tmp;
        return isPal(tmp);
    }
};
