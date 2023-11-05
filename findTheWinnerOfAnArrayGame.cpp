class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(arr.size() <= k){
            return *max_element(arr.begin(), arr.end());
        }
        deque<int> dq(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        bool flag = true;
        while(flag){
            int i = dq.front();
            dq.pop_front();
            int j = dq.front();
            dq.pop_front();
            int a = max(i, j);
            int b = min(i, j);
            dq.push_front(a);
            dq.push_back(b);
            mp[a]++;
            if(mp[a] >= k)
                return a;
        }
        return 0;
    }
};
