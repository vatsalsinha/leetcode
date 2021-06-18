class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // unordered_set<int> s;
        // for(int i = 0; i < n; i++){
        //     s.insert(i);
        // }
        // for(auto e : edges){
        //     if(s.find(e[1]) != s.end())
        //         s.erase(e[1]);
        // }
        // vector<int> res(s.begin(), s.end());
        // return res;
        vector<int> res, seen(n);
        for(auto e : edges)
            seen[e[1]] = 1;
        for(int i = 0; i < n; i++)
            if(seen[i] == 0)
                res.push_back(i);
        return res;
    }
};
