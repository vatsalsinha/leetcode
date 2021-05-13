class Solution {
public:
    int numSquares(int n) {
       /* DYNAMIC PROGRAMMING APPROACH
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int sq = 1; sq < n+1; sq++){
            for(int i = 1; i*i <= sq; i++){
                dp[sq] = min(dp[sq], dp[sq-(i*i)]+1);
            }
        }
        return dp[n];
        */
        //bfs:
        unordered_set<int> visited;
        vector<int> vec;
        queue<int> q;
        int step = 1;
        for(int i= 1; i*i <= n; i++){
            if(i*i == n)
                return step;
            q.push(i*i);
            vec.push_back(i*i);
            visited.insert(i*i);
        }
        while(!q.empty()){
            step++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                int num = q.front();
                for(auto v : vec){
                    int sum = num + v;
                    if(sum == n)
                        return step;
                    if(sum < n && !visited.count(sum)){
                        q.push(sum);
                        visited.insert(sum);
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};
