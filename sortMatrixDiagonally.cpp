class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < (i ? 1 : n); j++){
                vector<int> tmp;
                while(i < m && j < n){
                    tmp.push_back(mat[i++][j++]);
                }
                sort(tmp.begin(), tmp.end());
                while(i && j){
                    mat[--i][--j] = tmp.back();
                    tmp.pop_back();
                }
            }
        }
        return mat;
    }
};
