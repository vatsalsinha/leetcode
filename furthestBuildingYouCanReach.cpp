class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        /* 
        Main idea is to use as much bricks as possible.
        When bricks become empty, then replace the bricks with ladders used, and get the used bricks back.
        If ladders become 0, then we cannot go further, so break;
        */
        priority_queue<int> pq;
        for(int i = 1; i < heights.size(); i++){
            int diff = heights[i] - heights[i-1];
            if(diff < 0)
                continue;
            pq.push(diff);
            bricks -= diff; // use bricks
            if(bricks < 0){
                bricks += pq.top();
                pq.pop();
                ladders--; // replace bricks with ladders.
            }
            if(ladders < 0)
                return i-1; // i is starting from 1
        }
        return heights.size()-1;
    }
};
