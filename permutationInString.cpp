class Solution {
public:
    bool check(int f1[], int f2[]){
        for(int i = 0; i < 26; i++){
            if(f1[i] != f2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(m < n)
            return false;
        int f1[26], f2[26];
        for(int i = 0; i < 26; i++){
            f1[i] = f2[i] = 0;
        }
        for(auto c : s1)
            f1[c-'a']++;
        for(int i = 0; i < n; i++)
            f2[s2[i]-'a']++;
        if(check(f1, f2))
            return true;
        int window_size = n;
        while(window_size < m){
            f2[s2[window_size] - 'a']++;
            f2[s2[window_size - n] - 'a']--;
            if(check(f1, f2))
                return true;
            window_size++;
        }
        return false;
    }
};
