class Solution {
public:
    int minSteps(string s, string t) {
        // multiset<char> st(s.begin(), s.end());
        // for(auto c : t){
        //     if(st.find(c) != st.end())
        //         st.erase(st.find(c));
        // }
        // return (int)st.size();
        
        // approach 2
        unordered_map<char, int> dict;
        int sum = 0;
        for(auto c : s)
            dict[c]++;
        for(auto c : t)
            dict[c]--;
        for(auto it : dict)
            if(it.second < 0)
                sum += it.second;
        return abs(sum);
    }
};
