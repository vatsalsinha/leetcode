class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0; // i = 0 signifies north direction
        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
                                        // N      E      S      W
        for(auto c : instructions){
            if(c == 'R'){
                i = (i+1)%4; // East wrt current Position
            }
            else if(c == 'L')
                i = (i+3) % 4; // West wrt current position
            else
                x += directions[i][0], y += directions[i][1]; // north wrt curr pos
        }
        return (x == 0 && y == 0) || i > 0; // if currently we are at the origin OR we are not facing North
    }
};
