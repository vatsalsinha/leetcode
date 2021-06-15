class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int j = 0;
        unordered_map<char, int> dict;
        for(int i = 0; i < s.length(); i++)
            dict[s[i]] = i;
        int partitionedAt = 0;
        for(int i = 0; i < s.length(); i++){
            j = max(j, dict[s[i]]);
            if(i == j){
                ans.push_back(i-partitionedAt+1);
                partitionedAt = i+1;
            }
        }
        return ans;
    }
};