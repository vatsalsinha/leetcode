class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '1')
                count++;
        string ans(s.size(), '0');
        ans[ans.size()-1] = '1';
        count--;
        int i = 0;
        while(count > 0){
            ans[i++] = '1';
            count--;
        }   
        return ans;
    }
};
