class Solution {
public:
    string reverseOnlyLetters(string S) {
//         int n = s.size();
//         string ans;
//         for(int i = s.size()-1; i > -1; i--){
//             if(isalpha(s[i]))
//                 ans += s[i];
//         }
//         for(int i = 0; i < s.size(); i++){
//             if(!isalpha(s[i])){
//                 string tmp(1, s[i]);
//                 ans.insert(i, tmp);
//             }
//         }
        
//         return ans;
        int i = 0;
        int j = S.length()-1;
        
        while(i < j ){
            //if S[i] not a letter, increment to next
            if(!isalpha(S[i])) {
                i++;
                continue;
            }
            //if S[j] not a letter, decrement to next
            if(!isalpha(S[j])) {
                j--;
                continue;
            }
            
            //both are letters, swap & move i & j
            swap(S[i],S[j]);
            i++;
            j--;
            
        }       
        return S;
    }
};
