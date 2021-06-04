class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        int t = columnNumber;
        while(t != 0){
            int f = t % 26;
            char c; 
            if(f == 0)
                c = 'Z';
            else 
                c = (char)(64+f);
            res += c;
            t = (t-1)/26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
