class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> umap;
        for(int i = 0; i < groupSizes.size(); i++){
            umap[groupSizes[i]].push_back(i);
            if(umap[groupSizes[i]].size() == groupSizes[i]){
                ans.push_back(umap[groupSizes[i]]);
                umap[groupSizes[i]].clear();
            }
        }
        /* 
            {
                1: [5],
                3: [0,1,2,3,4,6]
            }
        */
        return ans;
    }
};
