class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> vec(102, vector<double>(102,0)); 	
        vec[0][0] += (double)poured;
        for(int i = 0; i < query_row+1; i++){
            for(int j = 0; j < i+1; j++){
                double k = (vec[i][j] - 1) / 2.0;
                if(k > 0){
                    vec[i+1][j] += k;
                    vec[i+1][j+1] += k;
                }
            }
        }
        return 1 < vec[query_row][query_glass] ? 1 : vec[query_row][query_glass];
    }
};
