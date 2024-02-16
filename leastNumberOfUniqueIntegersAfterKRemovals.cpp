//Custom Comparator for Priority Queue
class Compare {
public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(auto i : arr)
            mp[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(auto it : mp){
            pq.push({it.first, it.second});
        }
        while(k--){
            auto t = pq.top();
            pq.pop();
            t.second--;
            if(t.second)
                pq.push(t);
        }
        return (int)pq.size();;       
    }
};
/*

4 : 1
3 : 3
1 : 2
2 : 1

*/
