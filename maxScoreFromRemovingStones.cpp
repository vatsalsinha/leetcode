class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // vector<int> nums;
        // nums.push_back(a);
        // nums.push_back(b);
        // nums.push_back(c);
        // int ans = 0;
        // sort(nums.begin(), nums.end());
        // while(nums[1] + nums[0] > nums[2]){
        //     nums[0]--;
        //     nums[1]--;
        //     ans++;
        // }
        // ans += min(nums[0]+nums[1], nums[2]);
        // return ans;
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int ans = 0;
        while(pq.size() >= 2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x > 0 && y > 0){
                pq.push(x-1);
                pq.push(y-1);
                ans++;
            }
        }
        return ans;
    }
};
