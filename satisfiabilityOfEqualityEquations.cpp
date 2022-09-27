class Solution {
public:
    int parent[26];
    int find(int x){
        if(x == parent[x])
            return x;
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }
    void unian(int x, int y){
        x = find(x);
        y = find(y);
        parent[x] = y;
    }
    bool equationsPossible(vector<string>& equations) {
        memset(parent, -1, sizeof parent);
        for(auto e : equations){
            if(e[1] == '=')
                unian(e[0]-'a', e[3]-'a');
        }
        
        for(auto e : equations){
            if(e[1] == '!' && find(e[3]-'a') == find(e[0]-'a'))
                return 0;
        }
        return 1;
    }
};
