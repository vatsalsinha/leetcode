class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> ipos;
        for(int i = 0; i < profits.size(); i++){
            ipos.push_back({capital[i], profits[i]});
        }
        sort(ipos.begin(), ipos.end());
        int j = 0;
        priority_queue<int> pq;
        for(int i = 0; i < k; i++){
            while(j < profits.size() && ipos[j].first <= w){
                pq.push(ipos[j++].second);
            }
            if(pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
