class Solution {
public:
    string modifyString(string s) {
        for(int i = 0;i < s.size();i++){
            if(s[i] == '?'){
                
                if(i == 0){    // if we are starting then we have to check only next character
                    if(i + 1 < s.size()){
                        if(s[i+1] != 'a') 
                            s[i] = 'a';
                        else 
                            s[i] = 'b';
                    } 
                    else 
                        s[i] = 'a';
                }
                
                else if(i == s.size() - 1){     // if we are at last position
                    if(s[i-1] != 'a') 
                        s[i] = 'a';
                    else 
                        s[i] = 'b';
                }
                
                else{
                    if(s[i + 1] != 'a' && s[i-1] != 'a') 
                        s[i] = 'a';
                    else if(s[i + 1] != 'b' && s[i-1] != 'b') 
                        s[i] = 'b';
                    else 
                        s[i] = 'c';
                }
            }
        }
        return s;
    }
};
