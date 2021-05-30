class Solution {
public:
    bool check(string s, string t){
        unordered_map<char,char> charMap;
        for(int i=0;i<s.length();i++)
        {
            auto it=charMap.find(s[i]);
            if(it==charMap.end())
                charMap[s[i]] = t[i];
            else
            {
                if(t[i]!=it->second)
                   return false;
            }
        }
        
       return true;

    }
    bool isIsomorphic(string s, string t) {
        return check(s,t)&&check(t,s);
    }
};
