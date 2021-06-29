class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        bool board[8][8] = {};
        for(auto q : queens)
            board[q[0]][q[1]] = true;
        vector<vector<int>> res;
        for(int i = -1; i < 2; i++){
            for(int j = -1; j < 2; j++){ // simulating all the directions where we could search
                if(i==0 && j==0)
                    continue;
                int x = king[0] + i;
                int y = king[1] + j;
                while(min(x,y) >= 0 && max(x,y) < 8){
                    if(board[x][y]){
                        res.push_back({x,y});
                        break;
                    }
                    x += i, y += j;
                }
            }
        }
        return res;
    }
};
