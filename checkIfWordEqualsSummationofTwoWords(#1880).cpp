class Solution {
public:
    int calculate(string s){
        // string res;
        // for(char c : s){
        //     res += to_string((int) c-97);
        // }
        // cout<<res<<" ";
        // int n = stoi(res);
        // return n;
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            res = res*10 + (s[i]-'a');
        }
        return res;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int A, B, C;
        A = calculate(firstWord);
        B = calculate(secondWord);
        C = calculate(targetWord);
        return A+B == C;
    }
};
