class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        /*
        A[i][0] is worth 1 << (N - 1) points, more than the sum of (A[i][1] + .. + A[i][N-1]).
        We need to toggle all A[i][0] to 1, here I toggle all lines for A[i][0] = 0.
        
        A[i][j] is worth 1 << (N - 1 - j) For every col, I count the current number of 1s. After step 1, A[i][j] becomes 1 if A[i][j] == A[i][0]. if M - cur > cur, we can toggle this column to get more 1s. max(cur, M - cur) will be the maximum number of 1s that we can get.
        */
        int M = grid.size(), N = grid[0].size(), res = (1 << (N - 1)) * M;
        for (int j = 1; j < N; j++) {
            int cur = 0;
            for (int i = 0; i < M; i++) cur += grid[i][j] == grid[i][0];
            res += max(cur, M - cur) * (1 << (N - j - 1));
        }
        return res;
        // int n = grid.size();
        // int m = grid[0].size();
        // for(int i = 0; i < n; i++){
        //     if(grid[i][0] == 0){ // greedy
        //         for(int j = 0; j < m; j++)
        //             grid[i][j] = 1-grid[i][j];
        //     }
        // }
        // for(int j = 0; j < m; j++){
        //     int cz = 0, co = 0;
        //     for(int i = 0; i < n; i++){
        //         if(grid[i][j] == 1)
        //             co++;
        //         else
        //             cz++;
        //     }
        //     if(cz > co){
        //         for(int i = 0; i < n; i++)
        //             grid[i][j] = 1-grid[i][j];
        //     }
        // }
        // int sum = 0;
        // for(int i = 0; i < n; i++){
        //     int p = 0;
        //     for(int j = m-1; j > -1; j--){
        //         sum += grid[i][j]*pow(2,p++);
        //     }
        // }
        // return sum;
    }
};
