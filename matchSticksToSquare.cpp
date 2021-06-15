class Solution {
public:
    bitset<16> visited;
    
    bool dfs(vector<int> matchsticks, int target, int curSum, int i, int k){
        if(k == 1) // if k == 1 then we found all subsets
            return true;
        if(curSum == target) // we found one subset, go on to the next one starting from curr_sum = 0
            return dfs(matchsticks, target, 0, 0, k-1);
        if(i >= matchsticks.size())
            return false;
        for(int j = i; j < matchsticks.size(); j++){ 
            // if we visited an index already or curr_sum + matchsticks[j] > target then we can't use it
            if(curSum + matchsticks[j] <= target && !visited[j]){
                visited[j] = true;
                if(dfs(matchsticks, target, curSum+matchsticks[j], j+1, k))
                    return true;
                visited[j] = false;
            }
        }
        return false;            
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if(!matchsticks.size())
            return false;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0)
            return false;
        return dfs(matchsticks, sum/4, 0, 0, 4);
    }
};
