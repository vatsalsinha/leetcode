class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        int tot = R * C;
        int steps = 1;
        int count = 0;
        while(count < tot){
            for(int i = 0; i < steps; i++){
                if(r0 < R && r0 >= 0 && c0 < C && c0 >= 0){
                    res.push_back({r0,c0});
                    count++;
                }
                c0++;
            }
            for(int i = 0; i < steps; i++){
                if(r0 < R && r0 >= 0 && c0 < C && c0 >= 0){
                    res.push_back({r0,c0});
                    count++;
                }
                r0++;
            }
            steps++;
            for(int i = 0; i < steps; i++){
                if(r0 < R && r0 >= 0 && c0 < C && c0 >= 0){
                    res.push_back({r0,c0});
                    count++;
                }
                c0--;
            }
            for(int i = 0; i < steps; i++){
                if(r0 < R && r0 >= 0 && c0 < C && c0 >= 0){
                    res.push_back({r0,c0});
                    count++;
                }
                r0--;
            }
            steps++;
        }
        return res;
    }
};
