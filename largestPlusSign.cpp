class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for(auto m : mines){
            grid[m[0]][m[1]] = 0;
        }
        vector<vector<int>> lR(n, vector<int>(n,0));
        vector<vector<int>> rL(n, vector<int>(n,0));
        vector<vector<int>> tB(n, vector<int>(n,0));
        vector<vector<int>> bT(n, vector<int>(n,0));
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0)
                    sum = 0;
                else
                    sum += grid[i][j];
                lR[i][j] = sum;
            }
        }
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if(grid[j][i] == 0)
                    sum = 0;
                else
                    sum += grid[j][i];
                tB[j][i] = sum;
            }
        }
        for(int i = n-1; i > -1; i--){
            int sum = 0;
            for(int j = n-1; j > -1; j--){
                if(grid[i][j] == 0)
                    sum = 0;
                else
                    sum += grid[i][j];
                rL[i][j] = sum;
            }
        }
        for(int i = n-1; i > -1; i--){
            int sum = 0;
            for(int j = n-1; j > -1; j--){
                if(grid[j][i] == 0)
                    sum = 0;
                else
                    sum += grid[j][i];
                bT[j][i] = sum;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int tmp = min(min(lR[i][j], rL[i][j]), min(tB[i][j], bT[i][j]));
                ans = max(ans, tmp);
            }
        }   
        return ans;
    }
};