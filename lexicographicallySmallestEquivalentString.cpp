class Solution {
public:
    int findParent(int c, vector<int>& parent){
        if(parent[c] == c)
            return c;
        return parent[c] = findParent(parent[c], parent);
    }
    void unian(int c, int d, vector<int>& parent){
        c = findParent(c, parent);
        d = findParent(d, parent);
        if(c == d)
            return;
        if(c < d)
            parent[d] = c;
        else
            parent[c] = d;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for(int i = 0; i < 26; i++)
            parent[i] = i;
        int n = s1.size();
        for(int i = 0; i < n; i++){
            unian(s1[i]-'a', s2[i]-'a', parent);
        }
        string s = "";
        for(int i = 0; i < 26; i++)
            cout<<i<<":"<<parent[i]<<"\n";
        for(int i = 0; i < baseStr.size(); i++){
            s += (char)findParent(baseStr[i]-'a', parent)+'a';
        }
        return s;
    }
};
