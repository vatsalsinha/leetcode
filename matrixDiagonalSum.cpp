class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = 0; i < mat.size(); i++){
            sum += mat[i][i];
        }
        for(int i = mat.size()-1; i > -1; i--){
            sum += mat[mat.size()-i-1][i];
        }
        return mat.size() % 2 ? sum - mat[mat.size()/2][mat.size()/2] : sum;
    }
};
