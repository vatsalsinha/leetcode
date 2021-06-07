class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string tmp = "";
        int i = 0;
        while(i < s.size()){
			if(s[i] == ' '){
				v.push_back(tmp);
				tmp = "";
			}
			else{
				tmp += s[i];
			}
			i++;
		}
        v.push_back(tmp);
        if(v.size() != pattern.size())
            return false;
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        for(int i = 0; i < pattern.size(); i++){
            if(mp1.find(pattern[i]) == mp1.end()){
                mp1[pattern[i]] = v[i];
                //cout<<"mp1"<<" "<<pattern[i]<<":"<<v[i]<<" ";
            }
            if(mp2.find(v[i]) == mp2.end()){
                mp2[v[i]] = pattern[i];
                //cout<<"mp2"<<" "<<v[i]<<":"<<pattern[i]<<" ";
            }
            if(mp1[pattern[i]] != v[i] || mp2[v[i]] != pattern[i])
                return false;
            cout<<v[i];
        }
        return true;
    }
};
