class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> dict;
        for(auto n : arr)
            dict[n]++;
        priority_queue<int> pq; // always use a pq when you know will have to sort values;
        for(auto it : dict)
            pq.push(it.second);
        int res = 0, count = 0;
        while(count * 2 < arr.size()){
            res++;
            count += pq.top();
            pq.pop();
        }
        return res;
    }
};
