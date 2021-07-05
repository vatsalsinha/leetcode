class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res(r, vector<int>(c,0));
        if(r*c != mat.size()*mat[0].size())
            return mat;
        for(int i = 0; i < r*c; i++){
            res[i/c][i%c] = mat[i/mat[0].size()][i%mat[0].size()];
        }
        return res;
    }
};
