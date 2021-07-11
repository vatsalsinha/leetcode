class Solution {
public:
    //unordered_map<char, int> dict;
    string frequencySort(string s) {
        // stl method
        // for(auto c : s)
        //     dict[c]++;
        // sort(s.begin(), s.end(), [&] (char a, char b){ return dict[a] > dict[b] || (dict[a] == dict[b] && a < b);});
        // return s;
        
        //priority queue
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> pq;
        for(char c : s)
            freq[c]++;
        for(auto it : freq){
            pq.push({it.second, it.first});
        }
        string res;
        while(!pq.empty()){
            res += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        return res;
    }
};
