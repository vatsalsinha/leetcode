class Solution {
public:
    bool isMatch(string s, string str){
        int i = 0, j = 0;
        int m = s.size(), n = str.size();
        if(m - n < 0)
            return false;
        while(i < m && j < n){
            if(s[i] == str[j]){
                int count1 = repeatedLen(s, i);
                int count2 = repeatedLen(str, j);
                if(count1 < 3 && count1 != count2 || count1 >=3 && count1 < count2)
                    return false;
                i += count1;
                j += count2;
            }
            else
                return false;
        }
        return i == m && j == n;
    }
    int repeatedLen(string s, int pos){
        int j = pos;
        int count = 0;
        while(j < s.size() && s[j] == s[pos]){
            count++;
            j++;
        }
        return count;
    }
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for(auto str : words){
            if(isMatch(s, str))
                ans++;
        }
        return ans;
    }
};
