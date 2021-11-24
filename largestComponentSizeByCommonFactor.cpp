class Solution {
public:
    int parent[100001];
    int rank[100001];
    int findParent(int n){
        if(n == parent[n])
            return n;
        return parent[n] = findParent(parent[n]);
    }
    void unian(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u != v){
            if(rank[u] > rank[v])
                parent[v] = u;
            else if(rank[u] < rank[v])
                parent[u] = v;
            else{
                parent[u] = v;
                rank[v]++;
            }
        }
    }
    int largestComponentSize(vector<int>& nums) {
        for(int i = 0; i < 100001; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        for(int i = 0; i < nums.size(); i++){
            for(int j = 2; j*j <= nums[i]; j++){
                if(nums[i] % j == 0){
                    unian(nums[i], j);
                    unian(nums[i], nums[i]/j); // unioning all factors of nums[i]
                }
            }
        }
        unordered_map<int, int> mp;
        int ans = 1;
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, ++mp[findParent(nums[i])]); //checking for all available factors
        }
        return ans;
    }
};
