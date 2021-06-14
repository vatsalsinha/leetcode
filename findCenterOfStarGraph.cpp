class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // unordered_map<int, int> umap;
        // for(int i = 0; i < edges.size(); i++){
        //     for(int j = 0; j < edges[i].size(); j++){
        //         umap[edges[i][j]]++;
        //     }
        // }
        // for(auto it : umap){
        //     if(it.second == edges.size())
        //         return it.first;
        // }
        // return -1;
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};
