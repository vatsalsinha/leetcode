class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); i++){
            pq.push(stones[i]);
        }
        while(!pq.empty() && pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a==b)
                continue;
            else
                pq.push(a-b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

/*

2 7 4 1 8 1
1 1 2 4 7 8
1 1 1 2 4
1 1 1 2
1 1 1
1 0
*/
