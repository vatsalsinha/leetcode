class Solution {
public:
    int maxRepeating(string sequence, string word) {
        // if(word.size() == sequence.size()){
        //     if(word == sequence)
        //         return 1;
        //     else 
        //         return 0;
        // }
        // int count = 0;
        // string s;
        // int n = word.size();
        // for(int i = 0; i < sequence.size(); i++){
        //     s = sequence.substr(i,n);
        //     if(s == word){
        //         int c = 1;
        //         for(int j = i+n; j < sequence.size(); j+=n){
        //             if(sequence.substr(j, n) == word){
        //                 c++;
        //             }
        //             else
        //                 break;
        //         }
        //         count = max(count, c);
        //     }
        // }
        // return count;
        int count = 0;
        string tmp = word;
        while(sequence.find(tmp) != string::npos){ //until the end of the string
            count++;
            tmp += word;
        }
        return count;
    }
};
