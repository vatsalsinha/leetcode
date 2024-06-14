class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : hand)
            pq.push(i);
        int i = 0;
        int val = pq.top();
        pq.pop();
        while(pq.size() && i < groupSize){
            if(val != pq.top())
                return 0;
            val = pq.top();
            pq.pop();
            i++;
            if(i == groupSize)
                i = 0;
        }
        return 1;
        
    }
};
