class Solution {
public:
    vector<int> parent, rank;
    int findParent(int n){
        if(n == parent[n])
            return n;
        return n = findParent(parent[n]);
    }
    void unian(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u != v){
            if(rank[u] > rank[v])
                parent[v] = u;
            else if(rank[u] < rank[v])
                parent[u] = v;
            else{
                parent[u] = v;
                rank[v]++;
            }
        }
    }
    void makeSet(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = -1;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // find the number of connected components
        int n = s.size();
        parent.resize(n);
        rank.resize(n);
        makeSet(n);
        for(auto p : pairs){
            unian(p[0], p[1]);
        }
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[findParent(i)].push_back(i);
        }
        for(auto it : mp){
            string st = "";
            for(auto v : it.second){
                st += s[v];
            }
            sort(st.begin(), st.end());
            int j = 0;
            for(auto i : it.second)
                s[i] = st[j++];
        }
        return s;
    }
};
