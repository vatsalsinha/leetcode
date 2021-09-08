    class Solution {
    public:
        /* 
        Let shifts = [3,5,9], s = "abc"
suffixSum for shifts = [17,14,9]
The first character of the string , ie 'a' is shifted to total of 17 (3 times in the first shift, 8 times in the second shift, and 17 times in third shift). Similarly, rest of the characters are shifted.
        */
        // void shift(string& str,int shiftNumber, int index){
        //     for(int i = 0; i < index; i++){
        //         int key = (str[i]-'a' + shiftNumber)%26;
        //         str[i] = (char)(97+key);
        //     }
        // }
        string shiftingLetters(string s, vector<int>& shifts) {
            int n = shifts.size();
            string a = s;
            int suffixSum[n+1];
            suffixSum[n] = 0;
            for(int i = n-1; i > -1; i--){
                suffixSum[i] = suffixSum[i+1] + shifts[i];
                suffixSum[i] %= 26;
            }
            for(int i = 0; i < n; i++){
                int key = (a[i]-'a' + suffixSum[i])%26;
                a[i] = (char)(97+key);
            }
            return a;
        }
    };
