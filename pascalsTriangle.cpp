class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p(numRows);
        for(int i = 0; i < numRows; i++){
            vector<int> tmp(i+1);
            for(int j = 0; j < i+1; j++){
                if(i == 0 && j == 0)
                    tmp[j] = 1;
                else if(j == 0)
                    tmp[j] = p[i-1][j];
                else if(i == j)
                    tmp[j] = p[i-1][j-1];
                else
                    tmp[j] = p[i-1][j-1] + p[i-1][j];
            }
            p[i] = tmp;
        }
        return p;
    }
};
