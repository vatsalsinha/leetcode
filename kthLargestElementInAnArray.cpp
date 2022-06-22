class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //O(nlogk)
        priority_queue<int, vector<int>, greater<int> > pq; // min heap
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
    }
};
