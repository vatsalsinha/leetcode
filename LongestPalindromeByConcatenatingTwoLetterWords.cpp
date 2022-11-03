class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        unordered_set<string> st;
        for(auto word : words)
            mp[word]++;
        int len = 0;
        bool flag = 0;
        for(string w : words){
            string rev = w;
            reverse(rev.begin(), rev.end());
            if(st.find(w) == st.end()){ // instead of decreasing count, using set for easiness 
                if(w == rev){
                    len += mp[w] / 2; // to maximise the length, we use even number of "already" palindromes. 
                }
                else
                    len += min(mp[w], mp[rev]);
                if(mp[w] % 2 == 1 && w == rev) // if palindrome, count of word is odd, insert in the middle
                    flag = 1;
                st.insert(w);
                st.insert(rev);
            }
        }
        len*=4; // since, 2words in the front, 2words in the end
        return flag ? len + 2 : len;
    }
};
