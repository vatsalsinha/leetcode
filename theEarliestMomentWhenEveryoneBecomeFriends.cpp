class Solution {
public:
    vector<int> parent, rank;
    bool static cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
    void makeSet(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int findParent(int n){
        if(n == parent[n])
            return n;
        return n = findParent(parent[n]);
    }
    void unian(int u, int v, int &N){
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
            N--;
        }
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        parent.resize(n);
        rank.resize(n);
        makeSet(n);
        int N = n;
        sort(logs.begin(), logs.end(), cmp);
        for(int i = 0; i < logs.size(); i++){
            unian(logs[i][1], logs[i][2], N);
            if(N == 1)
                return logs[i][0];
        }
        cout<<N;
        return -1;
    }
};