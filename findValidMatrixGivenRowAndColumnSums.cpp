class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> mat(rowSum.size(), vector<int>(colSum.size(),0));
        for(int i = 0; i < rowSum.size(); i++){
            for(int j = 0; j < colSum.size(); j++){
                mat[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= mat[i][j]; //https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/discuss/876904/Python-and-C%2B%2B-(Greedy)-Easy-python-solution.-Explained-using-images
                colSum[j] -= mat[i][j];
            }
        }
        return mat;
    }
};
