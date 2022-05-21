class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<int> q;
        int ans = 0;
        unordered_set<int> s;
        s.insert(amount);
        q.push(amount);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int tot = q.front();
                q.pop();
                if(tot == 0)
                    return ans;
                else if(tot < 0)
                    continue;
                else{
                    for(int i : coins){
                        int cur = tot - i;
                        if(s.find(cur) == s.end()){
                            q.push(cur);
                            s.insert(cur);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
