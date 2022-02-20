class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX, minN = INT_MAX;
        priority_queue<int> pq;
        for(auto i : nums){
            i = i%2 ? i*2 : i; // transform every odd to even, to handle only even arrays.
            pq.push(i);
            minN = min(minN, i);
        }
        while(pq.top() % 2 == 0){           //ensuring the loop runs only till every number is even
            res = min(res, pq.top()-minN);
            minN = min(minN, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res, pq.top()-minN);
    }
};
