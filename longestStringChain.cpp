class Solution {
public:
    bool static cmp(string& a, string& b){
        return a.size() < b.size();
    }
    bool check(string& a, string& b){
        if(a.size() != b.size()+1)
            return 0;
        int i = 0, j = 0;
        while(i < a.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return i == a.size() && j == b.size();
    }
    int longestStrChain(vector<string>& words) {
        //variation of Longest Increasing Subsequence
        sort(words.begin(), words.end(), cmp); // sort wrt to word_length in ascending order
        vector<int> dp(words.size(), 1);
        int maxi= 1;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < i; j++){
                if(check(words[i], words[j]) && dp[j]+1 > dp[i])
                    dp[i] = dp[j] + 1;
                
            }
            maxi = max(dp[i], maxi);
        }
        return maxi;
    }
};
