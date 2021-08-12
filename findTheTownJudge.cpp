class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        /* Approach 1
        vector<vector<int>> adjacency_matrix(n+1, vector<int> (n+1));
        for(auto t : trust){
            adjacency_matrix[t[0]][t[1]] = 1;
        }
        int leader = -1, pos = -1;
        for(int i = 1; i < n+1; i++){
            int tmp = 0;
            for(int j = 1; j < n+1; j++){
                tmp += adjacency_matrix[j][i];
            }
            if(tmp > leader){
                leader = tmp;
                pos = i;
            }
        }
        for(int i = 1; i < n+1; i++)
            if(adjacency_matrix[pos][i] == 1)
                return -1;
        return leader == n-1 ? pos : -1;
        */
        
        //approach 2
        vector<int> count(n + 1, 0);
        for (auto& t : trust)
            count[t[0]]--, count[t[1]]++;
        for (int i = 1; i <= n; ++i) {
            if (count[i] == n - 1) return i;
        }
        return -1;
    }
};
