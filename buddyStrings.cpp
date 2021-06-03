class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // if(s.length() != goal.length())
        //     return false;
        // if(s == goal && set<char>(s.begin(), s.end()).size() < s.size())
        //     return true;
        // vector<int> dif;
        // for(int i = 0; i < s.length(); i++)
        //     if(s[i] != goal[i])
        //         dif.push_back(i);
        // return dif.size() == 2 && s[dif[0]] == goal[dif[1]] && s[dif[1]] == goal[dif[0]];
        if (s == goal)
            return (set<char>(s.begin(), s.end()).size() < s.size()); // swap same letters in A
        
        int n = s.length();
        int l = 0, r = n-1;
        
        while(l < n && s[l] == goal[l])
            l++;
        while(r >= 0 && s[r] == goal[r])
            r--;
        if(l < r)
            swap(s[l], s[r]);
        
        return s == goal;
    }
};
