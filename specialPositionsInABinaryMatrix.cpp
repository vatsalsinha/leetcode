class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        vector<int> rs(mat.size()), cs(mat[0].size(), 0);
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j])
                    rs[i]++, cs[j]++;
            }
        }
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] && rs[i] == 1 && cs[j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};

/*

0 0
0 0 
1 0

*/
