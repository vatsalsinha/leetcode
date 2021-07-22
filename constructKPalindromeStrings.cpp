class Solution {
public:
    bool canConstruct(string s, int k) {
        //approach 1
        // if(s.size() < k)
        //     return false;
        // unordered_map<char, int> dict;
        // for(auto c : s)
        //     dict[c]++;
        // int count = 0;
        // for(auto it : dict){
        //     if(it.second % 2)
        //         count++;
        // }
        // return count <= k;
        
        //approach 2
        bitset<26> freq;
        for(auto c : s)
            freq.flip(c-'a');
        return freq.count() <= k && k <= s.size();
    }
};