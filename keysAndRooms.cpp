class Solution {
public:
    unordered_set<int> visited;
    unordered_set<int> keys;
    void dfs(vector<vector<int>> rooms, int curr){
        visited.insert(curr);
        for(auto l : rooms[curr]){
            keys.insert(l);
        }
        for(auto k : keys){
            if(visited.find(k) == visited.end())
                dfs(rooms, k);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);
        return visited.size() == rooms.size();
    }
};
