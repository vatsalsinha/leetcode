class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int num : piles)
            pq.push(num);
        
        while(k--){
            int t = pq.top();
            pq.pop();
            t = t - t/2;
            pq.push(t);
        }
        int ans = 0;
        while(!pq.empty()){
            cout<<pq.top()<<" ";
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
/*
5 4 9
pq = 5 5 4
t = 9 - 9/2 9 - 4 = 5

*/

